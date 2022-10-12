#include "thicknessmenu.h"

ThicknessMenu::ThicknessMenu(QWidget *parent): QMenu(tr("&Thickness"), parent)
{
    group = new QActionGroup(this);
    light = new QAction(tr("&light"), this);
    light->setData(QVariant(1));
    normal = new QAction(tr("&normal"), this);
    normal->setData(QVariant(3));
    bold = new QAction(tr("&bold"), this);
    bold->setData(QVariant(9));

    group->addAction(light);
    group->addAction(normal);
    group->addAction(bold);

    addAction(light);
    addAction(normal);
    addAction(bold);
}

ThicknessMenu::~ThicknessMenu() {
    delete light;
    delete normal;
    delete bold;
}
