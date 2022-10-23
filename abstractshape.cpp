#include "abstractshape.h"

AbstractShape::AbstractShape()
{

}

QRectF* AbstractShape::getBoundingRect() {
    return new QRectF(*_startPoint, *_endPoint);
}

AbstractShape::~AbstractShape() {
    delete _startPoint;
    delete _endPoint;
}
