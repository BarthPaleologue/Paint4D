#ifndef ELLIPSE_H
#define ELLIPSE_H

#include "abstractshape.h"

class Ellipse : public AbstractShape
{
public:
    Ellipse();

    Ellipse(QPen pen);

    void draw(QPainter* painter) override;
};

#endif // ELLIPSE_H
