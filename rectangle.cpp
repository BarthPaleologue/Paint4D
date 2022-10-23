#include "rectangle.h"

Rectangle::Rectangle()
{

}

void Rectangle::draw(QPainter* painter) {
    AbstractShape::draw(painter);
    painter->drawRect(getBoundingRect());
}
