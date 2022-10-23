#include "rectangle.h"

Rectangle::Rectangle(): AbstractShape() {

}

Rectangle::Rectangle(QPen pen): AbstractShape(pen) {

}

void Rectangle::draw(QPainter* painter) {
    AbstractShape::draw(painter);
    painter->drawRect(getBoundingRect());
}
