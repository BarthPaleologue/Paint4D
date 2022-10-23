#ifndef ELLIPSE_H
#define ELLIPSE_H

#include "abstractshape.h"

class Ellipse : public AbstractShape
{
public:
    Ellipse();
    void draw(QPainter* painter) override;
};

#endif // ELLIPSE_H
