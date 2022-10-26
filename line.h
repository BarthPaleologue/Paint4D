#ifndef LINE_H
#define LINE_H

#include "abstractshape.h"
#include <QPainter>

class Line : public AbstractShape
{
public:
    Line();

    Line(QPen pen);

    std::string serialize() override;

    void draw(QPainter* painter) override;
};

#endif // LINE_H
