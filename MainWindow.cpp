#include <QAction>
#include <QFileDialog>
#include <QMenuBar>
#include <QStatusBar>
#include <QToolBar>


#include <QDebug>
#include "MainWindow.hpp"


MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent) {
    QMenuBar* menubar = menuBar();
    createActions(menubar);

    QStatusBar* statusbar = statusBar();
    statusbar->showMessage(tr("Ready"));
    
    //setUnifiedTitleAndToolBarOnMac(true); 
}

MainWindow::~MainWindow() {

}

/* Slots */

void MainWindow::newfile() {
    return; 
}

void MainWindow::open() {
    const QString filename = QFileDialog::getOpenFileName(this);

    if (filename.isEmpty()) {
        qDebug() << "No filename was given, ignoring open";
        return;
    }

    qDebug() << "filename was given, filename: " + filename;
    openFile(filename);
}

void MainWindow::openFile(const QString& filename) {

}

void MainWindow::save() {
    return;
}

void MainWindow::saveas() {
    return;
}

void MainWindow::about() {
    return;
}

/* Populate the menubar with menu options and actions */
void MainWindow::createActions(QMenuBar* menubar) {
    //create menus
    QMenu* filemenu = menubar->addMenu(tr("&File"));
    QMenu* editmenu = menubar->addMenu(tr("&Edit"));
    QMenu* viewmenu = menubar->addMenu(tr("&View"));
    QMenu* helpmenu = menubar->addMenu(tr("&Help"));

    //create dropdown options / "actions"
    QAction* newf = new QAction("&New...", this);
    QAction* open = new QAction("&Open...", this);
    QAction* save = new QAction("&Save...", this);
    QAction* saveas = new QAction("&Save as...", this);
    QAction* quit = new QAction("&Quit", this);
    QAction* about = new QAction("&About", this);
    QAction* aboutqt = new QAction("&About Qt", this);

    //add keyboard shortcuts and bind them automatically to the choice
    newf->setShortcut(tr("CTRL+N"));
    open->setShortcut(tr("CTRL+O"));
    save->setShortcut(tr("CTRL+S")); 
    saveas->setShortcut(tr("SHIFT+CTRL+S"));
    quit->setShortcut(tr("CTRL+Q"));

    //show extra information when user hovers over option
    newf->setStatusTip(tr("Create a new Nametable"));
    open->setStatusTip(tr("Open a Nametable"));
    save->setStatusTip(tr("Save this Nametable"));
    saveas->setStatusTip(tr("Save this Nametable with a different filename"));
    quit->setStatusTip(tr("Quit the NESPPU-Tool Suite"));
    about->setStatusTip(tr("About NESPPU-Tools"));
    aboutqt->setStatusTip(tr("About Qt"));

    //link dropdown option to the appropriate menu
    filemenu->addAction(newf);
    filemenu->addAction(open);
    filemenu->addAction(save);
    filemenu->addAction(saveas);
    filemenu->addSeparator();
    filemenu->addAction(quit);
    helpmenu->addAction(about);
    helpmenu->addAction(aboutqt);

    //link dropdown option action to the appropriate slot
    //connect(newf, &QAction::triggered, this, &MainWindow::newfile);
    connect(open, &QAction::triggered, this, &MainWindow::open);
    connect(save, &QAction::triggered, this, &MainWindow::save);
    connect(saveas, &QAction::triggered, this, &MainWindow::saveas);
    connect(about, &QAction::triggered, this, &MainWindow::about);
    connect(quit, &QAction::triggered, qApp, QApplication::quit);
}

