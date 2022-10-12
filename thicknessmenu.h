#ifndef THICKNESSMENU_H
#define THICKNESSMENU_H

#include <QMenu>
#include <QActionGroup>
#include <QAction>

class ThicknessMenu : public QMenu
{
public:
    ThicknessMenu(QWidget *parent);
    inline QActionGroup *getActionGroup() { return group; };
    ~ThicknessMenu();
private:
    QActionGroup *group;
    QAction *light;
    QAction *normal;
    QAction *bold;
signals:
    void thicknessChanged();
};

#endif // THICKNESSMENU_H
