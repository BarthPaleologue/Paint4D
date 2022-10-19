#ifndef CANVAS_H
#define CANVAS_H

#include <QWidget>
#include <QPainter>
#include <QMouseEvent>
#include <QPaintEvent>
#include <QObject>

#include "abstractshape.h"


class Canvas: public QWidget
{
    Q_OBJECT
public:
    Canvas(QWidget *parent = nullptr);

    void mousePressEvent(QMouseEvent* e);
    void mouseReleaseEvent(QMouseEvent* e);
    void mouseMoveEvent(QMouseEvent* e);

    ~Canvas();
protected:
    virtual void paintEvent(QPaintEvent* e);
public slots:
    inline void update() { QWidget::update(); };
    void setColor(QAction* action);
    void setThickness(QAction* action);
    void setStyle(QAction* action);
    void setShape(QAction* action);
private:
    bool drawing = false;
    QPen *_pen;
    QPointF *_origin;
    QPointF *_destination;
    enum ShapeEnum _shape;
};

#endif // CANVAS_H
