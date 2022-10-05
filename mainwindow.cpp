#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    //ui->setupUi(this);
    statusBar();
    menuBar = new QMenuBar(this);
    setMenuBar(menuBar);
    fileMenu = menuBar->addMenu(tr("&File"));

    openAction = new QAction(QIcon(":/open.png"), tr("open"), this);
    openAction->setToolTip("Open File");
    connect(openAction, SIGNAL(triggered()), this, SLOT(openFile()));

    saveAction = new QAction(QIcon(":/save.png"), tr("save"), this);
    saveAction->setToolTip("Save file");
    connect(saveAction, SIGNAL(triggered()), this, SLOT(saveFile()));

    quitAction = new QAction(QIcon(":/quit.png"), tr("quit"), this);
    quitAction->setToolTip("Quitter");
    connect(quitAction, SIGNAL(triggered()), this, SLOT(quitApp()));

    fileMenu->addAction(openAction);
    fileMenu->addAction(saveAction);
    fileMenu->addAction(quitAction);

    toolBar = new QToolBar(this);
    addToolBar(Qt::TopToolBarArea, toolBar);
    toolBar->addAction(openAction);
    toolBar->addAction(saveAction);
    toolBar->addAction(quitAction);

    textInput = new QTextEdit("écrire ici...", this);
    setCentralWidget(textInput);
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
        textInput->setText(QString::fromStdString(stringBuffer));
     }
}

void MainWindow::saveFile() {
    QString filename = "Data.txt";
    QFile file(filename);
    if (file.open(QIODevice::ReadWrite)) {
        QTextStream stream(&file);
        stream << textInput->toPlainText() << Qt::endl;
    }
}

void MainWindow::quitApp() {
    exit(0);
}

MainWindow::~MainWindow()
{
    delete ui;
}

