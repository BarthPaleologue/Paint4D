#include "rectangle.h"

Rectangle::Rectangle()
{

}

void Rectangle::draw(QPainter* painter) {
    painter->drawRect(*getBoundingRect());
}
