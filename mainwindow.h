#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMenuBar>
#include <QToolBar>
#include <QAction>
#include <QIcon>
#include <QFileDialog>
#include <QDialog>
#include <QCloseEvent>
#include <fstream>
#include <string>

#include "canvas.h"
#include "colormenu.h"
#include "thicknessmenu.h"
#include "stylemenu.h"
#include "shapemenu.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

    void closeEvent(QCloseEvent *event);

    ~MainWindow();

public slots:
    void openFile();
    void saveFile();
    void quitApp();

private:
    Ui::MainWindow *ui;

    QMenuBar *menuBar;
    QToolBar *toolBar;

    QMenu *fileMenu;
    ColorMenu *colorMenu;
    ThicknessMenu *thicknessMenu;
    StyleMenu *styleMenu;
    ShapeMenu *shapeMenu;

    QAction *openAction;
    QAction *saveAction;
    QAction *quitAction;

    QWidget* centralWidget;

    Canvas *canvas;

};
#endif // MAINWINDOW_H
