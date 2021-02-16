#include <QAction>
#include <QFileDialog>
#include <QMenuBar>
#include <QMessageBox>
#include <QStatusBar>
#include <QToolBar>
#include <QTextEdit>

#include <QDebug>
#include "MainWindow.hpp"


//TODO: emit a signal when the document is modified: "documentModified"
//      this will alert the user to save their latest changes before quitting, or
//      creating a new file.
//
//      use a custom quit() slot which checks for the "documentModififed" signal
//      and prompts the user if they want to save their changes first
//
//      create a recent files submenu just like every other program on the planet
//      so the user can choose older, recent files to open


MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent) {
    setUnifiedTitleAndToolBarOnMac(true); 
    setAttribute(Qt::WA_DeleteOnClose);

    menubar = menuBar();
    initMenuBar(menubar);

    statusbar = statusBar();
    statusbar->showMessage(tr("Ready"));

    QTextEdit* textEdit = new QTextEdit;
    setCentralWidget(textEdit);
}

MainWindow::~MainWindow() {

}

/* SLOTS */

void MainWindow::newf() {
    ACTIVE_FILE = "";
    //TODO: DESTROY THE CURRENT NAMETABLE VIEW, UNLOAD THE ATTRIBUTE TABLE AND
    //UNLOAD THE PALLETE
}

void MainWindow::open() {
    const QString filepath = QFileDialog::getOpenFileName(this, tr("Open File"),
                             "", tr("Nametable Files (*.bin *.s *.*)"));

    if (filepath.isEmpty()) {
        qDebug() << "WARN: No filepath was given, ignoring open";
        return;
    }

    qDebug() << "filepath was given, filepath: " + filepath;
    openFile(filepath);
}

void MainWindow::save() {
    if (ACTIVE_FILE.isEmpty()) {
        saveas();   //trigger the slot, safe defense against empty files
    } else {
        saveFile(ACTIVE_FILE);
    }
}

void MainWindow::saveas() {
    QString filepath = QFileDialog::getSaveFileName(this, tr("Save File As"),
                             "", tr("Nametable Files (*.bin *.s *.*)"));
    
    if (filepath.isEmpty()) {
        qDebug() << "WARN: No filepath is given, ignoring save";
        return;
    }

    qDebug() << "filepath was given, filepath: " + filepath;
    saveFile(filepath);
}

void MainWindow::about() {
    QMessageBox::about(this, tr("About NESPPU-TOOLS"),
            tr("This program is inspired by the original NES Screen Tool by Shiru.\n"
               "It is intended to be a similar tool with better portability.\n\n"
               "This program and author are not affiliated or supported by Nintendo.\n"
               "This program is provided \"as-is\" with no warranty of any kind\n"
               "including the implied warranty of merchantibility.\n"
               "Use at your own risk."));
}

void MainWindow::undo() {

}

void MainWindow::redo() {

}

void MainWindow::fullscreen() {
    Qt::WindowStates currentstate = windowState();
    setWindowState(currentstate ^ Qt::WindowFullScreen);
}


/* FUNCTIONS */


/* Opens a file and provides a valid nametable handler */
void MainWindow::openFile(const QString& filepath) {
    QFile file(filepath);

    if (!file.open(QFile::ReadOnly)) {
        qDebug() << "ERROR: File does not exist or file cannot be read";
        QMessageBox::critical(this, tr("Open File"),
                tr("The file could not be found:\n%1")
                .arg(filepath));
        return;
    }

    int filesize = file.bytesAvailable();

    if (filesize > 1024) {
        file.close();
        qDebug() << "ERROR: File does not fit in 1024 bytes, fix the nametable file";
        QMessageBox::critical(this, tr("Open File"),
                tr("Nametable file cannot be opened due to a bad file size.\n"
                   "File size is not exactly 1024 bytes. (%1 bytes)\n"
                   "Given file: %2")
                .arg(filesize)
                .arg(filepath));
        return;
    }

    //now that the file is valid, create a custom nametable widget here
    //create nametable view or create nametable object and link it to layout
    //nametable object code/views should be in a separate file(s) with their own
    //slots

    statusbar->showMessage(tr("Nametable opened"), 4000);
}


/* Saves the open file to a given directory on disk */
void MainWindow::saveFile(const QString& filepath) {
    QFile file(filepath);

    if (!file.open(QFile::WriteOnly)) {
        QMessageBox::warning(this, tr("Save File"),
                tr("Cannot write to file %1:\n%2")
                .arg(filepath)
                .arg(file.errorString()));
        return;
    }

    //write to file first
    ACTIVE_FILE = filepath;
    statusbar->showMessage(tr("Nametable saved"), 4000);
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

    //make options/actions into checkboxes (simplest way)
    //fscreenAct->setCheckable(true);

    //add keyboard shortcuts and bind them automatically to the choice
    newAct->setShortcut(QKeySequence::New);
    openAct->setShortcut(QKeySequence::Open);
    saveAct->setShortcut(QKeySequence::Save);
    saveasAct->setShortcut(QKeySequence::SaveAs);
    quitAct->setShortcut(QKeySequence::Quit);
    undoAct->setShortcut(Qt::CTRL + Qt::Key_Z);
    redoAct->setShortcut(Qt::CTRL + Qt::Key_Y);
    fscreenAct->setShortcut(Qt::Key_F11);

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
    connect(newAct, &QAction::triggered, this, &MainWindow::newf);
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

