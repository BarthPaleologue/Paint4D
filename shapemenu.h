#ifndef SHAPEMENU_H
#define SHAPEMENU_H

#include <QMenu>
#include <QActionGroup>

class ShapeMenu : public QMenu
{
public:
    ShapeMenu(QWidget *parent);
    inline QActionGroup *getActionGroup() { return group; };
    ~ShapeMenu();
private:
    QActionGroup *group;
    QAction *line;
    QAction *rectangle;
    QAction *ellipse;
signals:
    void shapeChanged();
};

#endif // SHAPEMENU_H
