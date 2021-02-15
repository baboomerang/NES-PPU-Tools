#pragma once

#include <QMainWindow>
#include <QApplication>

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget* parent = nullptr);
    virtual ~MainWindow();

signals:
    void preferences();

private:
    QString ACTIVE_FILE;
/*
    QAction* newAct;
    QAction* openAct;
    QAction* saveAct;
    QAction* saveasAct;
    QAction* quitAct;
    QAction* undoAct;
    QAction* redoAct;
    QAction* prefsAct;
    QAction* fscreenAct;
    QAction* aboutAct;
    QAction* aboutqtAct;
*/
    QMenuBar* menubar;
    QStatusBar* statusbar;
    void initMenuBar(QMenuBar*);
    void openFile(const QString&);
    void saveFile(const QString&);

private slots:
    void newf();
    void open();
    void save();
    void saveas();
    void about();
    void undo();
    void redo();
    void fullscreen();
};
