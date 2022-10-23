#ifndef ABSTRACTSHAPE_H
#define ABSTRACTSHAPE_H

#include <QPointF>
#include <QPainter>
#include <QRectF>
#include <QPen>

enum ShapeEnum {
    LINE, RECTANGLE, ELLIPSE
};

class AbstractShape
{
public:
    AbstractShape();

    AbstractShape(QPen pen);

    inline void setStartPoint(QPointF point) { _startPoint = point; };

    inline void setEndPoint(QPointF point) { _endPoint = point; };

    inline QRectF getBoundingRect() { return QRectF(_startPoint, _endPoint); };

    inline virtual void draw(QPainter *painter) { painter->setPen(_pen); };

    ~AbstractShape();
protected:
    QPointF _startPoint = QPointF(0, 0);
    QPointF _endPoint = QPointF(0, 0);
    QPen _pen;
};

#endif // ABSTRACTSHAPE_H
