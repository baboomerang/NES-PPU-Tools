#ifndef MENUBAR_H
#define MENUBAR_H

#include <QMainWindow>
#include <QApplication>

class Menubar : public QMainWindow {
    Q_OBJECT

public:
    Menubar(QWidget* parent = nullptr);
    virtual ~Menubar();

private:

};


#endif //MENUBAR_H
