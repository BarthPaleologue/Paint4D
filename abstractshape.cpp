#include "abstractshape.h"

AbstractShape::AbstractShape()
{

}

AbstractShape::~AbstractShape() {
    delete _startPoint;
    delete _endPoint;
}
