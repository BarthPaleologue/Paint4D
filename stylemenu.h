#ifndef STYLEMENU_H
#define STYLEMENU_H

#include <QMenu>
#include <QActionGroup>

class StyleMenu : public QMenu
{
public:
    StyleMenu(QWidget *parent);
    inline QActionGroup *getActionGroup() { return group; };
    ~StyleMenu();
private:
    QActionGroup *group;
    QAction *normal;
    QAction *dashed;
    QAction *dots;
signals:
    void styleChanged();
};

#endif // STYLEMENU_H
