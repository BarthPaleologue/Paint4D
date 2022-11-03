#ifndef CANVAS_H
#define CANVAS_H

#include <QWidget>
#include <QPainter>
#include <QMouseEvent>
#include <QKeyEvent>
#include <QWheelEvent>
#include <QPaintEvent>
#include <QObject>
#include <QAction>
#include <vector>
#include <string>

#include "abstractshape.h"


class Canvas: public QWidget {

    Q_OBJECT

public:

    Canvas(QWidget *parent = nullptr);

    void deserialize(std::string serialized);

    std::string serialize();

    void setSelectedShapesColorToCurrentPenColor();

    void mousePressEvent(QMouseEvent* e);

    void mouseReleaseEvent(QMouseEvent* e);

    void mouseMoveEvent(QMouseEvent* e);

    void keyPressEvent(QKeyEvent * e);

    void keyReleaseEvent(QKeyEvent *e);

    void wheelEvent(QWheelEvent* e);

    ~Canvas();

protected:

    virtual void paintEvent(QPaintEvent* e);

public slots:

    inline void update() { QWidget::update(); };

    void setColor(QAction* action);

    void setRed(int red);

    void setGreen(int green);

    void setBlue(int blue);

    void setAlpha(int alpha);

    void setSelectedScale(int scale);

    void setThickness(QAction* action);

    void setStyle(QAction* action);

    void setShape(QAction* action);

signals:
    void updateScale(int);
    void updateRed(int);
    void updateGreen(int);
    void updateBlue(int);
    void updateAlpha(int);

private:

    void removeShape(AbstractShape* shape);

    void increaseScaleSelected(float addScale);

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
