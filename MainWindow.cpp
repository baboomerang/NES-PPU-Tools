#include <QAction>
#include <QFileDialog>
#include <QMenuBar>
#include <QMessageBox>
#include <QStatusBar>
#include <QToolBar>
#include <QTextEdit>

#include <QDebug>
#include "MainWindow.hpp"


MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent) {
    setAttribute(Qt::WA_DeleteOnClose);

    QMenuBar* menubar = menuBar();
    initMenuBar(menubar);

    QStatusBar* statusbar = statusBar();
    statusbar->showMessage(tr("Ready"));

    QTextEdit* textEdit = new QTextEdit;
    setCentralWidget(textEdit);
    
    //setUnifiedTitleAndToolBarOnMac(true); 
}

MainWindow::~MainWindow() {

}

/* SLOTS */

//==== PUBLIC SLOTS ============






//==== PRIVATE SLOTS ============

void MainWindow::newfile() {

}

void MainWindow::open() {
    const QString filepath = QFileDialog::getOpenFileName(this);

    if (!filepath.isEmpty()) {
        qDebug() << "filepath was given, filepath: " + filepath;
        openFile(filepath);
    }
}

void MainWindow::openRecent() {

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
void MainWindow::openFile(const QString& filepath) {
    QFile file(filepath);

    if (!file.open(QFile::ReadOnly)) {
        qDebug() << "ERROR: File does not exist or file cannot be read";
        return;
    }

    if (file.bytesAvailable() != 1024) {
        qDebug() << "ERROR: File is not exactly 1024 bytes, fix the nametable file";
        return;
    }

    /*if (!file.open(QFile::ReadOnly)) {
        QMessageBox::warning(this, tr("File Error"),
                             tr("The file could not be found:\n%1").arg(filepath));
        return;
    }*/
}

/* Populate the menubar with menus and actions */
void MainWindow::initMenuBar(QMenuBar* menubar) {
    //create menus
    QMenu* filemenu = menubar->addMenu(tr("&File"));
    QMenu* editmenu = menubar->addMenu(tr("&Edit"));
    QMenu* viewmenu = menubar->addMenu(tr("&View"));
    QMenu* helpmenu = menubar->addMenu(tr("&Help"));

    //create dropdown options / "actions"
    QAction* newAct = new QAction(tr("&New..."), this);
    QAction* openAct = new QAction(tr("&Open..."), this);
    QAction* saveAct = new QAction(tr("&Save..."), this);
    QAction* saveasAct = new QAction(tr("Save &As..."), this);
    QAction* quitAct = new QAction(tr("&Quit"), this);
    QAction* undoAct = new QAction(tr("&Undo"), this);    
    QAction* redoAct = new QAction(tr("&Redo"), this);
    QAction* prefsAct = new QAction(tr("&Preferences"), this);
    QAction* fscreenAct = new QAction(tr("Fullscreen"), this);
    QAction* aboutAct = new QAction(tr("About"), this);
    QAction* aboutqtAct = new QAction(tr("About Qt"), this);

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

