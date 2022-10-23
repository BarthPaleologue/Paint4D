#include "line.h"

Line::Line(): AbstractShape()
{

}

void Line::draw(QPainter* painter) {
    AbstractShape::draw(painter);
    painter->drawLine(_startPoint.x(), _startPoint.y(), _endPoint.x(), _endPoint.y());
}
