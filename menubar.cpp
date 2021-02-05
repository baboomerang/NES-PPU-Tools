#include <QMenuBar>
#include <QAction>
#include "menubar.hpp"

Menubar::Menubar(QWidget* parent) : QMainWindow(parent) {

    //TODO: Add status tooltip (when you hover the mouse over the menu option)
    //Change the font of the menubar so it looks nicer

    QMenu* file = menuBar()->addMenu("&File");
    auto* newfile = new QAction("&New");
    auto* open = new QAction("&Open");
    auto* quit = new QAction("&Exit", this);
    file->addAction(newfile);
    file->addAction(open);
    file->addAction(quit);

    QMenu* edit = menuBar()->addMenu("&Edit");
    QMenu* view = menuBar()->addMenu("&View");
    QMenu* help = menuBar()->addMenu("&Help");

    connect(quit, &QAction::triggered, qApp, QApplication::quit);
}

Menubar::~Menubar() {

}


