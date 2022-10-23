#ifndef CANVAS_H
#define CANVAS_H

#include <QWidget>
#include <QPainter>
#include <QMouseEvent>
#include <QKeyEvent>
#include <QPaintEvent>
#include <QObject>
#include <vector>

#include "abstractshape.h"


class Canvas: public QWidget {

    Q_OBJECT

public:

    Canvas(QWidget *parent = nullptr);

    void mousePressEvent(QMouseEvent* e);

    void mouseReleaseEvent(QMouseEvent* e);

    void mouseMoveEvent(QMouseEvent* e);

    void keyPressEvent(QKeyEvent * e);

    void keyReleaseEvent(QKeyEvent *e);

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

    void removeShape(AbstractShape* shape);

    float mouseLastX = 0.0;
    float mouseLastY = 0.0;

    bool isDrawing = false;
    bool isSelecting = true;
    bool isShiftPressed = false;

    QPen _pen;
    QPen _selectionPen;

    enum ShapeEnum _shape = LINE;
    std::vector<AbstractShape*> _shapes{};
    std::vector<AbstractShape*> _selectedShapes{};
};

#endif // CANVAS_H
