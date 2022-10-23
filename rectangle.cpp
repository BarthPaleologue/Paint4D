#include "rectangle.h"

Rectangle::Rectangle()
{

}

void Rectangle::draw(QPainter* painter) {
    painter->drawRect(_startPoint->x(), _startPoint->y(), _endPoint->x() - _startPoint->x(), _endPoint->y() - _startPoint->y());
}
