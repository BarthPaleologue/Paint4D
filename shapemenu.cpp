#include "shapemenu.h"
#include "abstractshape.h"

ShapeMenu::ShapeMenu(QWidget *parent): QMenu(tr("Shape"), parent)
{
    group = new QActionGroup(this);
    line = new QAction(QIcon(":/icons/line.png"), tr("&line"), this);
    line->setData(QVariant(static_cast<int>(ShapeEnum::LINE)));
    rectangle = new QAction(QIcon(":/icons/rectangle.png"), tr("&rectangle"), this);
    rectangle->setData(QVariant(static_cast<int>(ShapeEnum::RECTANGLE)));
    ellipse = new QAction(QIcon(":/icons/ellipse.png"), tr("&ellipse"), this);
    ellipse->setData(QVariant(static_cast<int>(ShapeEnum::ELLIPSE)));

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
