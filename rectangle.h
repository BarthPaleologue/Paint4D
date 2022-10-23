#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "abstractshape.h"

class Rectangle : public AbstractShape
{
public:
    Rectangle();

    Rectangle(QPen pen);

    void draw(QPainter* painter) override;
};

#endif // RECTANGLE_H
