#include "canvas.h"

Canvas::Canvas(QWidget *parent): QWidget(parent)
{
    setMinimumSize(200, 200);
    _pen = new QPen(Qt::red);
    _origin = new QPointF();
    _destination = new QPointF();
}

void Canvas::paintEvent(QPaintEvent *e) {
    QWidget::paintEvent(e);

    QPainter painter(this);
    painter.setPen(*_pen);

    painter.drawLine(_origin->x(), _origin->y(), _destination->x(), _destination->y());
}

void Canvas::mousePressEvent(QMouseEvent *e) {
    drawing = true;
    *_origin = e->position();
    *_destination = e->position();

    update();
}

void Canvas::mouseReleaseEvent(QMouseEvent *e) {
    drawing = false;
    *_destination = e->position();

    update();
}

void Canvas::mouseMoveEvent(QMouseEvent *e) {
    if(drawing) {
        *_destination = e->position();
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

Canvas::~Canvas() {

}
