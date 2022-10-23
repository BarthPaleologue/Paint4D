#include "ellipse.h"

Ellipse::Ellipse()
{

}

void Ellipse::draw(QPainter* painter) {
    painter->drawEllipse(*getBoundingRect());
}

