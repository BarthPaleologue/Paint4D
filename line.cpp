#include "line.h"

Line::Line(): AbstractShape() {

}

Line::Line(QPen pen): AbstractShape(pen) {

}

void Line::draw(QPainter* painter) {
    AbstractShape::draw(painter);
    QPointF startPoint = getStartPoint();
    QPointF endPoint = getEndPoint();
    painter->drawLine(startPoint.x(), startPoint.y(), endPoint.x(), endPoint.y());
}
