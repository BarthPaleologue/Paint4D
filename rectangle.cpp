#include "rectangle.h"

Rectangle::Rectangle(): AbstractShape() {

}

Rectangle::Rectangle(QPen pen): AbstractShape(pen) {

}

std::string Rectangle::serialize() {
    std::string result = AbstractShape::serialize();
    return "Rectangle " + result;
}

void Rectangle::draw(QPainter* painter) {
    AbstractShape::draw(painter);
    painter->drawRect(getBoundingRect());
}
