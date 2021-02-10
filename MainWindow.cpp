#include <QAction>
#include <QFileDialog>
#include <QMenuBar>
#include <QMessageBox>
#include <QStatusBar>
#include <QToolBar>


#include <QDebug>
#include "MainWindow.hpp"


MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent) {
    QMenuBar* menubar = menuBar();
    initMenuBar(menubar);

    QStatusBar* statusbar = statusBar();
    statusbar->showMessage(tr("Ready"));
    
    //setUnifiedTitleAndToolBarOnMac(true); 
}

MainWindow::~MainWindow() {

}

/* SLOTS */

void MainWindow::newfile() {
    return; 
}

void MainWindow::open() {
    const QString filepath = QFileDialog::getOpenFileName(this);

    if (filepath.isEmpty()) {
        qDebug() << "No filepath was given, ignoring open";
        return;
    }

    qDebug() << "filepath was given, filepath: " + filepath;
    openFile(filepath);
}

void MainWindow::save() {
    //QString filepath = QFileDialog::getSaveFileName(this, tr("Save A"), filename);

    return;
}

void MainWindow::saveas() {
    return;
}

void MainWindow::about() {
    QMessageBox::about(this, tr("About NESPPU-TOOLS"),
            tr("Example description: Insert text here"));
    return;
}


/* FUNCTIONS */


/* Opens a file and provides a valid file handler */
void MainWindow::openFile(const QString& filename) {

}

/* Populate the menubar with menu options and actions */
void MainWindow::initMenuBar(QMenuBar* menubar) {
    //create menus
    QMenu* filemenu = menubar->addMenu(tr("&File"));
    QMenu* editmenu = menubar->addMenu(tr("&Edit"));
    QMenu* viewmenu = menubar->addMenu(tr("&View"));
    QMenu* helpmenu = menubar->addMenu(tr("&Help"));

    //create dropdown options / "actions"
    QAction* newf = new QAction("&New...", this);
    QAction* open = new QAction("&Open...", this);
    QAction* save = new QAction("&Save...", this);
    QAction* saveas = new QAction("Save &As...", this);
    QAction* quit = new QAction("&Quit", this);
    QAction* undo = new QAction("&Undo", this);    
    QAction* redo = new QAction("&Redo", this);
    QAction* prefs = new QAction("&Preferences", this);
    QAction* fscreen = new QAction("Fullscreen", this);
    QAction* about = new QAction("About", this);
    QAction* aboutqt = new QAction("About Qt", this);

    //add keyboard shortcuts and bind them automatically to the choice
    newf->setShortcut(QKeySequence::New);
    open->setShortcut(QKeySequence::Open);
    save->setShortcut(QKeySequence::Save);
    saveas->setShortcut(QKeySequence::SaveAs);
    quit->setShortcut(QKeySequence::Quit);
    undo->setShortcut(QKeySequence::Undo);
    redo->setShortcut(QKeySequence::Redo);
    fscreen->setShortcut(QKeySequence::FullScreen);

    //show extra information when user hovers over the option
    newf->setStatusTip(tr("Create a new Nametable"));
    open->setStatusTip(tr("Open a Nametable"));
    save->setStatusTip(tr("Save this Nametable"));
    saveas->setStatusTip(tr("Save this Nametable with a different filename"));
    quit->setStatusTip(tr("Quit the NESPPU-Tool Suite"));
    undo->setStatusTip(tr("Undo the last change"));
    redo->setStatusTip(tr("Redo the last change"));
    prefs->setStatusTip(tr("Open the preferences dialog"));
    fscreen->setStatusTip(tr("Toggle fullscreen view"));
    about->setStatusTip(tr("About NESPPU-Tools"));
    aboutqt->setStatusTip(tr("About Qt"));

    //link dropdown option to the appropriate menu
    filemenu->addAction(newf);
    filemenu->addAction(open);
    filemenu->addAction(save);
    filemenu->addAction(saveas);
    filemenu->addSeparator();
    filemenu->addAction(quit);
    editmenu->addAction(undo);
    editmenu->addAction(redo);
    editmenu->addAction(prefs);
    viewmenu->addAction(fscreen);
    helpmenu->addAction(about);
    helpmenu->addAction(aboutqt);

    //link dropdown option action to the appropriate slot
    connect(newf, &QAction::triggered, this, &MainWindow::newfile);
    connect(open, &QAction::triggered, this, &MainWindow::open);
    connect(save, &QAction::triggered, this, &MainWindow::save);
    connect(saveas, &QAction::triggered, this, &MainWindow::saveas);
    connect(about, &QAction::triggered, this, &MainWindow::about);
    connect(aboutqt, &QAction::triggered, qApp, QApplication::aboutQt);
    connect(quit, &QAction::triggered, qApp, QApplication::quit);
}

