#include "abstractshape.h"

AbstractShape::AbstractShape()
{
    _pen = QPen();
}

AbstractShape::AbstractShape(QPen pen) {
    _pen = pen;
}

void AbstractShape::translate(float dx, float dy) {
    _startPoint.setX(_startPoint.x() + dx);
    _endPoint.setX(_endPoint.x() + dx);

    _startPoint.setY(_startPoint.y() + dy);
    _endPoint.setY(_endPoint.y() + dy);
}

void AbstractShape::setPosition(QPointF position) {
    QPointF currentPosition = getBoundingRect().center();
    translate(-currentPosition.x() + position.x(), -currentPosition.y() + position.y());
}

AbstractShape::~AbstractShape() {

}
