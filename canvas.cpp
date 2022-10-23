#include "canvas.h"
#include "line.h"

Canvas::Canvas(QWidget *parent): QWidget(parent)
{
    setMinimumSize(200, 200);
    _pen = new QPen(Qt::red);
}

void Canvas::paintEvent(QPaintEvent *e) {
    QWidget::paintEvent(e);

    QPainter painter(this);
    painter.setPen(*_pen);

    for(unsigned int i = 0; i < _shapes.size(); i++) {
        _shapes[i]->draw(&painter);
    }
}

void Canvas::mousePressEvent(QMouseEvent *e) {
    drawing = true;
    _shapes.push_back(new Line());
    AbstractShape *shape = _shapes[_shapes.size() - 1];
    shape->setStartPoint(e->position());
    shape->setEndPoint(e->position());

    update();
}

void Canvas::mouseReleaseEvent(QMouseEvent *e) {
    drawing = false;
    update();
}

void Canvas::mouseMoveEvent(QMouseEvent *e) {
    if(drawing) {
        _shapes[_shapes.size() - 1]->setEndPoint(e->position());
        update();
    }
}

void Canvas::setColor(QAction* action) {
    _pen->setColor(QColor(action->data().toString()));
    update();
}

void Canvas::setThickness(QAction* action) {
    _pen->setWidth(action->data().toInt());
    update();
}

void Canvas::setStyle(QAction* action) {
    _pen->setStyle(static_cast<Qt::PenStyle>(action->data().toInt()));
    update();
}

void Canvas::setShape(QAction* action) {
    _shape = static_cast<ShapeEnum>(action->data().toInt());
    update();
}

Canvas::~Canvas() {

}
