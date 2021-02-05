#include <QApplication>
#include "menubar.hpp"

int main(int argc, char** argv) {
    QApplication app(argc, argv);

    Menubar window;
    window.resize(800, 600);
    window.setWindowTitle("QToolBar");
    window.show();

    return app.exec();
}
