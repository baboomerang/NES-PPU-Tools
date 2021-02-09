#pragma once

#include <QMainWindow>
#include <QApplication>

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget* parent = nullptr);
    virtual ~MainWindow();

    void openFile(const QString& filename);

private slots:
    //void newfile();
    void open();
    void save();
    void saveas();
    void about();
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
