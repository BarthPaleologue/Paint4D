#include <QMessageBox>
#include <iostream>

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setMinimumSize(400, 400);
    statusBar();

    menuBar = new QMenuBar(this);
    setMenuBar(menuBar);

    toolBar = new QToolBar(this);
    toolBar->setMovable(false);
    addToolBar(Qt::ToolBarArea::TopToolBarArea, toolBar);

    fileMenu = menuBar->addMenu(tr("&File"));

    openAction = new QAction(QIcon(":/icons/open.png"), tr("open"), this);
    connect(openAction, SIGNAL(triggered()), this, SLOT(openFile()));

    saveAction = new QAction(QIcon(":/icons/save.png"), tr("save"), this);
    connect(saveAction, SIGNAL(triggered()), this, SLOT(saveFile()));

    quitAction = new QAction(QIcon(":/icons/quit.png"), tr("quit"), this);
    quitAction->setToolTip("Quitter");
    connect(quitAction, SIGNAL(triggered()), this, SLOT(quitApp()));

    fileMenu->addAction(openAction);
    fileMenu->addAction(saveAction);
    fileMenu->addAction(quitAction);

    colorMenu = new ColorMenu(this);
    menuBar->addMenu(colorMenu);

    thicknessMenu = new ThicknessMenu(this);
    menuBar->addMenu(thicknessMenu);

    styleMenu = new StyleMenu(this);
    menuBar->addMenu(styleMenu);

    shapeMenu = new ShapeMenu(this);
    menuBar->addMenu(shapeMenu);

    toolBar->addAction(openAction);
    toolBar->addAction(saveAction);
    toolBar->addSeparator();
    toolBar->addActions(shapeMenu->getActionGroup()->actions());
    toolBar->addSeparator();
    toolBar->addActions(colorMenu->getActionGroup()->actions());
    toolBar->addSeparator();
    toolBar->addActions(styleMenu->getActionGroup()->actions());

    centralWidget = findChild<QWidget*>("centralwidget");

    canvas = new Canvas(centralWidget);

    connect(colorMenu->getActionGroup(), SIGNAL(triggered(QAction*)), canvas, SLOT(setColor(QAction*)));

    connect(thicknessMenu->getActionGroup(), SIGNAL(triggered(QAction*)), canvas, SLOT(setThickness(QAction*)));

    connect(styleMenu->getActionGroup(), SIGNAL(triggered(QAction*)), canvas, SLOT(setStyle(QAction*)));

    connect(shapeMenu->getActionGroup(), SIGNAL(triggered(QAction*)), canvas, SLOT(setShape(QAction*)));

    connect(findChild<QWidget*>("scaleSlider"), SIGNAL(valueChanged(int)), canvas, SLOT(setSelectedScale(int)));

    connect(findChild<QWidget*>("redSlider"), SIGNAL(valueChanged(int)), canvas, SLOT(setRed(int)));

    connect(findChild<QWidget*>("greenSlider"), SIGNAL(valueChanged(int)), canvas, SLOT(setGreen(int)));

    connect(findChild<QWidget*>("blueSlider"), SIGNAL(valueChanged(int)), canvas, SLOT(setBlue(int)));

    connect(findChild<QWidget*>("alphaSlider"), SIGNAL(valueChanged(int)), canvas, SLOT(setAlpha(int)));

    connect(canvas, SIGNAL(updateScale(int)), findChild<QWidget*>("scaleSlider"), SLOT(setValue(int)));

    connect(canvas, SIGNAL(updateRed(int)), findChild<QWidget*>("redSlider"), SLOT(setValue(int)));

    connect(canvas, SIGNAL(updateGreen(int)), findChild<QWidget*>("greenSlider"), SLOT(setValue(int)));

    connect(canvas, SIGNAL(updateBlue(int)), findChild<QWidget*>("blueSlider"), SLOT(setValue(int)));

    connect(canvas, SIGNAL(updateAlpha(int)), findChild<QWidget*>("alphaSlider"), SLOT(setValue(int)));

    setCentralWidget(centralWidget);
}

void MainWindow::openFile() {
     QFileDialog * dialog = new QFileDialog(this);
     QStringList fileNames;

     if (dialog->exec() == QDialog::Accepted) {
        fileNames = dialog->selectedFiles();
        QString filename = fileNames[0];
        std::ifstream reader(filename.toStdString());
        if (reader.is_open()) {
            std::string lineBuffer;
            while (std::getline(reader, lineBuffer)) {
                canvas->deserialize(lineBuffer);
            }
            reader.close();
        }
    }
}

void MainWindow::saveFile() {
    QString filename = QFileDialog::getSaveFileName(this, tr("Save File"),
                                "./untitled.txt",
                                tr("Text (*.txt)"));

    QFile file(filename);
    if (file.open(QIODevice::WriteOnly)) {
        file.resize(0);
        QTextStream stream(&file);
        stream << canvas->serialize().c_str();
        file.flush();
        file.close();
    }
}

void MainWindow::quitApp() {
    QApplication::quit();
}

void MainWindow::closeEvent(QCloseEvent *event) {
    event->ignore();
    if (QMessageBox::Yes == QMessageBox::question(this, "Exiting", "Are you sure you want to quit the app ?", QMessageBox::Yes | QMessageBox::No)) {
        event->accept();
    }
}

MainWindow::~MainWindow()
{
    delete ui;
    delete menuBar;
    delete fileMenu;
    delete openAction;
    delete saveAction;
    delete quitAction;
    delete canvas;
}

