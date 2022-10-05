#ifndef CANVAS_H
#define CANVAS_H

#include <QWidget>

class Canvas: public QWidget
{
public:
    Canvas(QWidget *parent);
signals:
    void mousePressed(int x, int y);
    void mouseReleased(int x, int y);
    void mouseMove(int x, int y);
};

#endif // CANVAS_H
