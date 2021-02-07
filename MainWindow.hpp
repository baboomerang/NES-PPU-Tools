#pragma once

#include <QMainWindow>
#include <QApplication>

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget* parent = nullptr);
    void loadFile(const QString &filename);

    virtual ~MainWindow();

private slots:
    //void newFile();
    //void open();
    //bool save();
    //bool saveAs();
    //void about();
    //void documentWasModified();

private:
    void createActions(QMenuBar*);
    //void createStatusBar(QStatusBar*);
    //void readSettings();
    //void writeSettings();
    //bool maybeSave();
    ///bool saveFile(const QString &filename);
    //void setCurrentFile(const QString &filename);
};
