#include "canvas.h"

Canvas::Canvas(QWidget *parent): QWidget(parent)
{
    setMinimumSize(200, 200);
    _origin = new QPointF();
    _destination = new QPointF();
}

void Canvas::paintEvent(QPaintEvent *e) {
    QWidget::paintEvent(e);

    QPen pen;
    pen.setStyle(Qt::DashDotDotLine);
    pen.setWidth(3);
    pen.setBrush(_color);

    QPainter painter(this);
    painter.setPen(pen);

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

void Canvas::setColor(QAction *action) {
    if(action->data() == 0) {
        _color = Qt::red;
    } else if(action->data() == 1) {
        _color = Qt::green;
    } else {
        _color = Qt::blue;
    }

    update();
}

Canvas::~Canvas() {

}
