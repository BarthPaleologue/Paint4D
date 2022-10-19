#include "shapemenu.h"
#include "abstractshape.h"

ShapeMenu::ShapeMenu(QWidget *parent): QMenu(tr("Shape"), parent)
{
    group = new QActionGroup(this);
    line = new QAction(tr("&line"), this);
    line->setData(QVariant(static_cast<int>(ShapeEnum::LINE)));
    rectangle = new QAction(tr("&rectangle"), this);
    rectangle->setData(QVariant(static_cast<int>(ShapeEnum::RECTANGLE)));
    ellipse = new QAction(tr("&ellipse"), this);
    ellipse->setData(QVariant(static_cast<int>(ShapeEnum::LINE)));

    group->addAction(line);
    group->addAction(rectangle);
    group->addAction(ellipse);

    addAction(line);
    addAction(rectangle);
    addAction(ellipse);
}

ShapeMenu::~ShapeMenu() {
    delete line;
    delete rectangle;
    delete ellipse;
}
