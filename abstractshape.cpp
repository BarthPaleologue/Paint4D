#include "abstractshape.h"

AbstractShape::AbstractShape()
{
    _pen = QPen();
}

AbstractShape::AbstractShape(QPen pen) {
    _pen = pen;
}

AbstractShape::~AbstractShape() {

}
