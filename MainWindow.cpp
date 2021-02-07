#include <QAction>
#include <QDebug>
#include <QMenuBar>
#include <QStatusBar>
#include <QToolBar>

#include "MainWindow.hpp"


MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent) {
    QMenuBar* menubar = menuBar();
    createActions(menubar);

    QStatusBar* statusbar = statusBar();
}

MainWindow::~MainWindow() {

}

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

    connect(quit, &QAction::triggered, qApp, QApplication::quit);
}

