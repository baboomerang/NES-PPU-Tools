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

}

void MainWindow::saveas() {

}

void MainWindow::about() {
    QMessageBox::about(this, tr("<b>About NESPPU-TOOLS</b>\n"),
            tr("<b>Example description: Insert text here</b>"
            "QMainWindow, \n QMenuBar and QtoolBar."));
}

void MainWindow::undo() {

}

void MainWindow::redo() {

}

void MainWindow::preferences() {

}

void MainWindow::fullscreen() {

}

/* FUNCTIONS */


/* Opens a file and provides a valid file handler */
void MainWindow::openFile(const QString& filename) {

}

/* Populate the menubar with menus and actions */
void MainWindow::initMenuBar(QMenuBar* menubar) {
    //create menus
    QMenu* filemenu = menubar->addMenu(tr("&File"));
    QMenu* editmenu = menubar->addMenu(tr("&Edit"));
    QMenu* viewmenu = menubar->addMenu(tr("&View"));
    QMenu* helpmenu = menubar->addMenu(tr("&Help"));

    //create dropdown options / "actions"
    QAction* newAct = new QAction("&New...", this);
    QAction* openAct = new QAction("&Open...", this);
    QAction* saveAct = new QAction("&Save...", this);
    QAction* saveasAct = new QAction("Save &As...", this);
    QAction* quitAct = new QAction("&Quit", this);
    QAction* undoAct = new QAction("&Undo", this);    
    QAction* redoAct = new QAction("&Redo", this);
    QAction* prefsAct = new QAction("&Preferences", this);
    QAction* fscreenAct = new QAction("Fullscreen", this);
    QAction* aboutAct = new QAction("About", this);
    QAction* aboutqtAct = new QAction("About Qt", this);

    //add keyboard shortcuts and bind them automatically to the choice
    newAct->setShortcut(QKeySequence::New);
    openAct->setShortcut(QKeySequence::Open);
    saveAct->setShortcut(QKeySequence::Save);
    saveasAct->setShortcut(QKeySequence::SaveAs);
    quitAct->setShortcut(QKeySequence::Quit);
    undoAct->setShortcut(QKeySequence::Undo);
    redoAct->setShortcut(QKeySequence::Redo);
    fscreenAct->setShortcut(QKeySequence::FullScreen);

    //show extra information when user hovers over the option
    newAct->setStatusTip(tr("Create a new Nametable"));
    openAct->setStatusTip(tr("Open a Nametable"));
    saveAct->setStatusTip(tr("Save this Nametable"));
    saveasAct->setStatusTip(tr("Save this Nametable with a different filename"));
    quitAct->setStatusTip(tr("Quit the NESPPU-Tool Suite"));
    undoAct->setStatusTip(tr("Undo the last change"));
    redoAct->setStatusTip(tr("Redo the last change"));
    prefsAct->setStatusTip(tr("Open the preferences dialog"));
    fscreenAct->setStatusTip(tr("Toggle fullscreen view"));
    aboutAct->setStatusTip(tr("About NESPPU-Tools"));
    aboutqtAct->setStatusTip(tr("About Qt"));

    //link dropdown option to the appropriate menu
    filemenu->addAction(newAct);
    filemenu->addAction(openAct);
    filemenu->addAction(saveAct);
    filemenu->addAction(saveasAct);
    filemenu->addSeparator();
    filemenu->addAction(quitAct);
    editmenu->addAction(undoAct);
    editmenu->addAction(redoAct);
    editmenu->addSeparator();
    editmenu->addAction(prefsAct);
    viewmenu->addAction(fscreenAct);
    helpmenu->addAction(aboutAct);
    helpmenu->addAction(aboutqtAct);

    //link dropdown option action to the appropriate slot
    connect(newAct, &QAction::triggered, this, &MainWindow::newfile);
    connect(openAct, &QAction::triggered, this, &MainWindow::open);
    connect(saveAct, &QAction::triggered, this, &MainWindow::save);
    connect(saveasAct, &QAction::triggered, this, &MainWindow::saveas);
    connect(quitAct, &QAction::triggered, qApp, QApplication::quit);
    connect(undoAct, &QAction::triggered, this, &MainWindow::undo);
    connect(redoAct, &QAction::triggered, this, &MainWindow::redo);
    connect(prefsAct, &QAction::triggered, this, &MainWindow::preferences);
    connect(fscreenAct, &QAction::triggered, this, &MainWindow::fullscreen);
    connect(aboutAct, &QAction::triggered, this, &MainWindow::about);
    connect(aboutqtAct, &QAction::triggered, qApp, QApplication::aboutQt);
}

