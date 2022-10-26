#ifndef ELLIPSE_H
#define ELLIPSE_H

#include "abstractshape.h"

class Ellipse : public AbstractShape
{
public:
    Ellipse();

    Ellipse(QPen pen);

    std::string serialize() override;

    void draw(QPainter* painter) override;
};

#endif // ELLIPSE_H
