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
    void newfile();
    void open();
    void openRecent();
    void save();
    void saveas();
    void about();
    void undo();
    void redo();
    void preferences();
    void fullscreen();
    //void documentWasModified();

private:
    void initMenuBar(QMenuBar*);
    //void createStatusBar(QStatusBar*);
    //void readSettings();
    //void writeSettings();
    //bool maybeSave();
    ///bool saveFile(const QString &filename);
    //void setCurrentFile(const QString &filename);
};
