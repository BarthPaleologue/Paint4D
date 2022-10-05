#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMenuBar>
#include <QAction>
#include <QIcon>
#include <QFileDialog>
#include <QDialog>
#include <fstream>
#include <string>

#include "canvas.h"
#include "colormenu.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void openFile();
    void saveFile();
    void quitApp();

private:
    Ui::MainWindow *ui;
    QMenuBar *menuBar;
    QMenu *fileMenu;
    ColorMenu *colorMenu;
    QAction *openAction;
    QAction *saveAction;
    QAction *quitAction;

    Canvas *canvas;

};
#endif // MAINWINDOW_H
