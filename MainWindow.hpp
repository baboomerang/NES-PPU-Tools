#pragma once

#include <QMainWindow>
#include <QApplication>

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget* parent = nullptr);
    virtual ~MainWindow();

private:

};
