#include <QApplication>
#include "MainWindow.hpp"

int main(int argc, char** argv) {
    QApplication app(argc, argv);

    MainWindow window;
    window.resize(800, 600);
    window.setWindowTitle("QToolBar");
    window.show();

    return app.exec();
}
