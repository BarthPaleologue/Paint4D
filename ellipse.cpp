#include "ellipse.h"

Ellipse::Ellipse(): AbstractShape() {

}

Ellipse::Ellipse(QPen pen): AbstractShape(pen) {

}

void Ellipse::draw(QPainter* painter) {
    AbstractShape::draw(painter);
    painter->drawEllipse(getBoundingRect());
}

