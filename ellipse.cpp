#include "ellipse.h"

Ellipse::Ellipse()
{

}

void Ellipse::draw(QPainter* painter) {
    AbstractShape::draw(painter);
    painter->drawEllipse(getBoundingRect());
}

