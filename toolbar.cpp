#include <QToolBar>
#include <QAction>
#include "toolbar.hpp"

Toolbar::Toolbar(QWidget* parent) : QMainWindow(parent) {

    QToolBar* toolbar = addToolBar("main toolbar");
    toolbar->setMovable(false);
    toolbar->addAction("File");
    toolbar->addAction("Edit");
    toolbar->addAction("Tools");
    toolbar->addSeparator();

    QAction* quit = toolbar->addAction("Quit Application");

    connect(quit, &QAction::triggered, qApp, &QApplication::quit);
}

Toolbar::~Toolbar() {
}
