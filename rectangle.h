#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "abstractshape.h"

class Rectangle : public AbstractShape
{
public:
    Rectangle();

    Rectangle(QPen pen);

    std::string serialize() override;

    void draw(QPainter* painter) override;
};

#endif // RECTANGLE_H
