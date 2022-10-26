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

    inline QPointF getStartPoint() { return (_startPoint - getCenter()) * _scale + getCenter(); };

    inline void setEndPoint(QPointF point) { _endPoint = point; };

    inline QPointF getEndPoint() { return (_endPoint - getCenter()) * _scale + getCenter(); };

    void translate(float dx, float dy);

    void setPosition(QPointF position);

    inline void setColor(QColor color) { _pen.setColor(color); };

    inline void setThickness(int thickness) { _pen.setWidth(thickness); };

    inline void setStyle(Qt::PenStyle style) { _pen.setStyle(style); };

    inline void setScale(float scale) { _scale = std::max(scale, 0.1f); };

    inline float getScale() { return _scale; };

    inline QRectF getBoundingRect() { return QRectF(getStartPoint(), getEndPoint()); };

    inline QPointF getCenter() { return (_startPoint + _endPoint) / 2.0; };

    inline QColor getColor() { return _pen.color(); };

    inline virtual void draw(QPainter *painter) { painter->setPen(_pen); };

    virtual ~AbstractShape();
protected:
    QPointF _endPoint = QPointF(0, 0);
    QPen _pen;
    float _scale = 1.0f;

private:
    QPointF _startPoint = QPointF(0, 0);
};

#endif // ABSTRACTSHAPE_H
