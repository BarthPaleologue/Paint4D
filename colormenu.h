#ifndef COLORMENU_H
#define COLORMENU_H

#include <QObject>
#include <QWidget>
#include <QMenu>
#include <QAction>
#include <QActionGroup>

class ColorMenu: public QMenu
{
public:
    ColorMenu(QWidget *parent = nullptr);
    inline QActionGroup *getActionGroup() { return group; };
    ~ColorMenu();
private:
    QActionGroup *group;
    QAction *red;
    QAction *green;
    QAction *blue;
signals:
    void colorChanged();
};

#endif // COLORMENU_H
