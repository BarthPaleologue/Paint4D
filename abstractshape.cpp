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

std::string AbstractShape::serialize() {
    std::string result = "";
    result += std::to_string(_startPoint.x()) + " ";
    result += std::to_string(_startPoint.y()) + " ";
    result += std::to_string(_endPoint.x()) + " ";
    result += std::to_string(_endPoint.y()) + " ";
    result += std::to_string(_scale) + " ";
    return result;
}

AbstractShape::~AbstractShape() {

}
