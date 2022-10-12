#include "stylemenu.h"

StyleMenu::StyleMenu(QWidget *parent): QMenu(tr("Style"), parent)
{
    group = new QActionGroup(this);
    normal = new QAction(tr("&normal"), this);
    normal->setData(QVariant(static_cast<int>(Qt::SolidLine)));
    dashed = new QAction(tr("&dashes"), this);
    dashed->setData(QVariant(static_cast<int>(Qt::DashLine)));
    dots = new QAction(tr("&dots"), this);
    dots->setData(QVariant(static_cast<int>(Qt::DotLine)));

    group->addAction(normal);
    group->addAction(dashed);
    group->addAction(dots);

    addAction(normal);
    addAction(dashed);
    addAction(dots);
}

StyleMenu::~StyleMenu() {
    delete normal;
    delete dashed;
    delete dots;
}

