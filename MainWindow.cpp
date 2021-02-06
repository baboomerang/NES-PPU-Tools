#include <QAction>
#include <QDebug>
#include <QMenuBar>
#include <QToolBar>

#include "MainWindow.hpp"


MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent) {
    QMenuBar* menubar = menuBar();

    QMenu* filemenu = menubar->addMenu(tr("&File"));
    QAction* newf = new QAction("&New", this);
    QAction* open = new QAction("&Open", this);
    QAction* save = new QAction("&Save", this);
    QAction* saveas = new QAction("&Save as", this);
    QAction* quit = new QAction("&Exit", this);

    filemenu->addAction(newf);
    filemenu->addAction(open);
    filemenu->addAction(save);
    filemenu->addAction(saveas);
    filemenu->addSeparator();
    filemenu->addAction(quit);

    newf->setShortcut(tr("CTRL+N"));
    open->setShortcut(tr("CTRL+O"));
    save->setShortcut(tr("CTRL+S")); 
    saveas->setShortcut(tr("SHIFT+CTRL+S"));
    quit->setShortcut(tr("CTRL+Q"));

    QMenu* editmenu = menubar->addMenu(tr("&Edit"));
    QMenu* viewmenu = menubar->addMenu(tr("&View"));
    QMenu* helpmenu = menubar->addMenu(tr("&Help"));

    connect(quit, &QAction::triggered, qApp, QApplication::quit);
}

MainWindow::~MainWindow() {

}
