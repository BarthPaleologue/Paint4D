#include "ellipse.h"

Ellipse::Ellipse(): AbstractShape() {

}

Ellipse::Ellipse(QPen pen): AbstractShape(pen) {

}


std::string Ellipse::serialize() {
    std::string result = AbstractShape::serialize();
    return "Ellipse " + result;
}

void Ellipse::draw(QPainter* painter) {
    AbstractShape::draw(painter);
    painter->drawEllipse(getBoundingRect());
}

