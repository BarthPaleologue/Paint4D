#include "line.h"

Line::Line(): AbstractShape() {

}

Line::Line(QPen pen): AbstractShape(pen) {

}

std::string Line::serialize() {
    std::string result = AbstractShape::serialize();
    return "Line " + result;
}

void Line::draw(QPainter* painter) {
    AbstractShape::draw(painter);
    QPointF startPoint = getStartPoint();
    QPointF endPoint = getEndPoint();
    painter->drawLine(startPoint.x(), startPoint.y(), endPoint.x(), endPoint.y());
}
