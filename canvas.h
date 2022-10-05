#ifndef CANVAS_H
#define CANVAS_H

#include <QWidget>
#include <QPainter>
#include <QMouseEvent>
#include <QPaintEvent>
#include <QObject>

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
private:
    bool drawing = false;
    QPointF *_origin;
    QPointF *_destination;
    enum Qt::GlobalColor _color = Qt::green;
};

#endif // CANVAS_H
