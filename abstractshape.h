#ifndef ABSTRACTSHAPE_H
#define ABSTRACTSHAPE_H

#include <QPointF>
#include <QPainter>

enum ShapeEnum {
    LINE, RECTANGLE, ELLIPSE
};

class AbstractShape
{
public:
    AbstractShape();
    inline void setStartPoint(QPointF point) { _startPoint->setX(point.x()); _startPoint->setY(point.y()); };
    inline void setEndPoint(QPointF point) { _endPoint->setX(point.x()); _endPoint->setY(point.y()); };
    inline virtual void draw(QPainter *painter) {};
    ~AbstractShape();
protected:
    QPointF* _startPoint = new QPointF(0, 0);
    QPointF* _endPoint = new QPointF(0, 0);
};

#endif // ABSTRACTSHAPE_H
