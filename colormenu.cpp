#include "colormenu.h"

ColorMenu::ColorMenu(QWidget *parent): QMenu(tr("&Color"), parent)
{
    group = new QActionGroup(this);
    red = new QAction(tr("&red"), this);
    red->setData(QVariant(QColor(Qt::red)));
    green = new QAction(tr("&green"), this);
    green->setData(QVariant(QColor(Qt::green)));
    blue = new QAction(tr("&blue"), this);
    blue->setData(QVariant(QColor(Qt::blue)));

    group->addAction(red);
    group->addAction(green);
    group->addAction(blue);

    addAction(red);
    addAction(green);
    addAction(blue);
}

ColorMenu::~ColorMenu() {
    delete red;
    delete green;
    delete blue;
}
