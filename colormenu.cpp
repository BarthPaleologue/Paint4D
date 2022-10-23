#include "colormenu.h"

ColorMenu::ColorMenu(QWidget *parent): QMenu(tr("&Color"), parent)
{
    group = new QActionGroup(this);
    red = new QAction(QIcon(":/icons/red.png"), tr("&red"), this);
    red->setData(QVariant(QColor(Qt::red)));
    green = new QAction(QIcon(":/icons/green.png"), tr("&green"), this);
    green->setData(QVariant(QColor(Qt::green)));
    blue = new QAction(QIcon(":/icons/blue.png"), tr("&blue"), this);
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
