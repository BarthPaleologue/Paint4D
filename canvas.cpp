#include "canvas.h"
#include "line.h"
#include "rectangle.h"
#include "ellipse.h"

Canvas::Canvas(QWidget *parent): QWidget(parent)
{
    setMinimumSize(800, 600);
    setFocusPolicy(Qt::FocusPolicy::StrongFocus);

    _pen = QPen(Qt::red);
    _pen.setWidth(3);


    _selectionPen = QPen();
    _selectionPen.setWidth(2);
    _selectionPen.setColor(QColor::fromCmyk(255, 0, 0, 128));
}

void Canvas::removeShape(AbstractShape* shape) {
    for(unsigned int i = 0; i < _shapes.size(); i++) {
        if(_shapes[i] == shape) {
            _shapes.erase(_shapes.begin() + i);
            break;
        }
    }
    delete shape;
}

void Canvas::paintEvent(QPaintEvent *e) {
    QWidget::paintEvent(e);

    QPainter painter(this);

    for(unsigned int i = 0; i < _shapes.size(); i++) {
        _shapes[i]->draw(&painter);
    }

    for(auto _selectedShape : _selectedShapes) {
        painter.setPen(_selectionPen);
        painter.drawRect(_selectedShape->getBoundingRect());
    }
}

void Canvas::mousePressEvent(QMouseEvent *e) {
    mouseLastX = e->position().x();
    mouseLastY = e->position().y();

    if(isSelecting) {
        for(auto shape : _shapes) {
            if(shape->getBoundingRect().contains(e->pos())) {
                for(auto selectedShape: _selectedShapes) {
                    if(selectedShape == shape) return;
                }
                if(!isShiftPressed) _selectedShapes.clear();
                _selectedShapes.push_back(shape);
                return;
            }
        }
        _selectedShapes.clear();
    }

    isDrawing = true;
    AbstractShape* newShape;
    switch(_shape) {
        case LINE:
            newShape = new Line(_pen);
            break;
        case RECTANGLE:
            newShape = new Rectangle(_pen);
            break;
        case ELLIPSE:
            newShape = new Ellipse(_pen);
            break;
    }

    newShape->setStartPoint(e->position());
    newShape->setEndPoint(e->position());

    _shapes.push_back(newShape);

    update();
}

void Canvas::mouseReleaseEvent(QMouseEvent *e) {
    if(isDrawing) {
        isDrawing = false;
        _selectedShapes.clear();
        _selectedShapes.push_back(_shapes[_shapes.size() - 1]);
    }
    update();
}

void Canvas::mouseMoveEvent(QMouseEvent *e) {
    for(auto _selectedShape : _selectedShapes) {
        _selectedShape->translate(e->position().x() - mouseLastX, e->position().y() - mouseLastY);
    }
    if(_selectedShapes.size() > 0) update();

    if(isDrawing) {
        _shapes[_shapes.size() - 1]->setEndPoint(e->position());
        update();
    }

    mouseLastX = e->position().x();
    mouseLastY = e->position().y();
}

void Canvas::keyPressEvent(QKeyEvent *e) {
    switch(e->key()) {
        case Qt::Key::Key_Escape:
            _selectedShapes.clear();
            update();
            break;
        case Qt::Key::Key_Shift:
            isShiftPressed = true;
            break;
        case Qt::Key::Key_Delete:
            for(auto selectedShape: _selectedShapes) removeShape(selectedShape);
            _selectedShapes.clear();
            update();
            break;
    }
}

void Canvas::keyReleaseEvent(QKeyEvent *e) {
    switch(e->key()) {
        case Qt::Key::Key_Shift:
            isShiftPressed = false;
            break;
    }
}

void Canvas::setColor(QAction* action) {
    QColor newColor = QColor(action->data().toString());
    _pen.setColor(newColor);
    for(auto _selectedShape : _selectedShapes) _selectedShape->setColor(newColor);
    update();
}

void Canvas::setThickness(QAction* action) {
    int newThickness = action->data().toInt();
    _pen.setWidth(newThickness);
    for(auto _selectedShape : _selectedShapes) _selectedShape->setThickness(newThickness);
    update();
}

void Canvas::setStyle(QAction* action) {
    Qt::PenStyle newPenStyle = static_cast<Qt::PenStyle>(action->data().toInt());
    _pen.setStyle(newPenStyle);
    for(auto _selectedShape : _selectedShapes) _selectedShape->setStyle(newPenStyle);
    update();
}

void Canvas::setShape(QAction* action) {
    _shape = static_cast<ShapeEnum>(action->data().toInt());
    update();
}

Canvas::~Canvas() {
    for(auto shape: _shapes) {
        delete shape;
    }
    _shapes.clear();
}
