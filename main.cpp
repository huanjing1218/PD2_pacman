#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("PACMAN");
    w.resize(560, 670);
    w.show();

    return a.exec();
}
