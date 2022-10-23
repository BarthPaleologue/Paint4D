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

    void translate(float dx, float dy);

    void setPosition(QPointF position);

    inline void setColor(QColor color) { _pen.setColor(color); };

    inline void setThickness(int thickness) { _pen.setWidth(thickness); };

    inline void setStyle(Qt::PenStyle style) { _pen.setStyle(style); };

    inline QRectF getBoundingRect() { return QRectF(_startPoint, _endPoint); };

    inline virtual void draw(QPainter *painter) { painter->setPen(_pen); };

    virtual ~AbstractShape();
protected:
    QPointF _startPoint = QPointF(0, 0);
    QPointF _endPoint = QPointF(0, 0);
    QPen _pen;
};

#endif // ABSTRACTSHAPE_H
