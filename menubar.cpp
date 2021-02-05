#include <QMenuBar>
#include <QAction>
#include "menubar.hpp"

Menubar::Menubar(QWidget* parent) : QMainWindow(parent) {

    //TODO: Add status tooltip (when you hover the mouse over the menu option)
    //Change the font of the menubar so it looks nicer

    QMenu* filemenu = menuBar()->addMenu("&File");
    auto* newfile = new QAction("&New", this);
    auto* open = new QAction("&Open", this);
    auto* save = new QAction("&Save", this);
    auto* saveas = new QAction("&Save as", this);
    auto* quit = new QAction("&Exit", this);

    newfile->setShortcut(tr("CTRL+N"));
    open->setShortcut(tr("CTRL+O"));
    save->setShortcut(tr("CTRL+S")); 
    saveas->setShortcut(tr("SHIFT+CTRL+S"));
    quit->setShortcut(tr("CTRL+Q"));

    filemenu->addAction(newfile);
    filemenu->addAction(open);
    filemenu->addAction(save);
    filemenu->addAction(saveas);
    filemenu->addSeparator();
    filemenu->addAction(quit);

    QMenu* edit = menuBar()->addMenu("&Edit");
    QMenu* view = menuBar()->addMenu("&View");
    QMenu* help = menuBar()->addMenu("&Help");

    connect(quit, &QAction::triggered, qApp, QApplication::quit);
}

Menubar::~Menubar() {

}


