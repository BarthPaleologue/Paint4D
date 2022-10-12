#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    //ui->setupUi(this);
    setMinimumSize(400, 400);
    statusBar();
    menuBar = new QMenuBar(this);
    setMenuBar(menuBar);
    fileMenu = menuBar->addMenu(tr("&File"));    

    fileMenu->addAction(openAction);
    fileMenu->addAction(saveAction);
    fileMenu->addAction(quitAction);

    openAction = new QAction(QIcon(":/icons/open.png"), tr("open"), this);
    openAction->setToolTip("Open File");
    connect(openAction, SIGNAL(triggered()), this, SLOT(openFile()));

    saveAction = new QAction(QIcon(":/icons/save.png"), tr("save"), this);
    saveAction->setToolTip("Save file");
    connect(saveAction, SIGNAL(triggered()), this, SLOT(saveFile()));

    quitAction = new QAction(QIcon(":/icons/quit.png"), tr("quit"), this);
    quitAction->setToolTip("Quitter");
    connect(quitAction, SIGNAL(triggered()), this, SLOT(quitApp()));

    colorMenu = new ColorMenu(this);
    menuBar->addMenu(colorMenu);

    thicknessMenu = new ThicknessMenu(this);
    menuBar->addMenu(thicknessMenu);

    styleMenu = new StyleMenu(this);
    menuBar->addMenu(styleMenu);

    canvas = new Canvas(this);

    connect(colorMenu->getActionGroup(), SIGNAL(triggered(QAction*)), canvas, SLOT(setColor(QAction*)));

    connect(thicknessMenu->getActionGroup(), SIGNAL(triggered(QAction*)), canvas, SLOT(setThickness(QAction*)));

    connect(styleMenu->getActionGroup(), SIGNAL(triggered(QAction*)), canvas, SLOT(setStyle(QAction*)));

    setCentralWidget(canvas);
}

void MainWindow::openFile() {
     QFileDialog * dialog = new QFileDialog(this);
     QStringList fileNames;

     if (dialog->exec( ) == QDialog::Accepted) {
        fileNames = dialog->selectedFiles();
        QString filename = fileNames[0];
        std::string stringBuffer = "";
        std::ifstream reader(filename.toStdString());
        if (reader.is_open()) {
            std::string lineBuffer;
            while (std::getline(reader, lineBuffer)) {
                stringBuffer += lineBuffer + "\n";
            }
            reader.close();
        }
    }
}

void MainWindow::saveFile() {
    QString filename = "Data.txt";
    QFile file(filename);
    if (file.open(QIODevice::ReadWrite)) {
        QTextStream stream(&file);
        file.close();
    }
}

void MainWindow::quitApp() {
    exit(0);
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

