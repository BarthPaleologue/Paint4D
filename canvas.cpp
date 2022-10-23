#include "canvas.h"
#include "line.h"
#include "rectangle.h"
#include "ellipse.h"

Canvas::Canvas(QWidget *parent): QWidget(parent)
{
    setMinimumSize(800, 600);
    _pen = QPen(Qt::red);
    _pen.setWidth(3);
}

void Canvas::paintEvent(QPaintEvent *e) {
    QWidget::paintEvent(e);

    QPainter painter(this);

    for(unsigned int i = 0; i < _shapes.size(); i++) {
        _shapes[i]->draw(&painter);
    }
}

void Canvas::mousePressEvent(QMouseEvent *e) {
    drawing = true;
    AbstractShape* newShape;
    switch(_shape) {
        case LINE:
            newShape = new Line(_pen);
            break;
        case RECTANGLE:
            newShape = new Rectangle(_pen);
            break;
        case ELLIPSE:
            newShape = new Ellipse(_pen);
            break;
    }

    newShape->setStartPoint(e->position());
    newShape->setEndPoint(e->position());

    _shapes.push_back(newShape);

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
    _pen.setColor(QColor(action->data().toString()));
    update();
}

void Canvas::setThickness(QAction* action) {
    _pen.setWidth(action->data().toInt());
    update();
}

void Canvas::setStyle(QAction* action) {
    _pen.setStyle(static_cast<Qt::PenStyle>(action->data().toInt()));
    update();
}

void Canvas::setShape(QAction* action) {
    _shape = static_cast<ShapeEnum>(action->data().toInt());
    update();
}

Canvas::~Canvas() {

}
