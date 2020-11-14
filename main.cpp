#include <QApplication>
#include "mainwindow.h"
#include<plate.h>
#include "tests.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Test::run();
    Test2::run();
    MainWindow w;
    w.show();
    return a.exec();
}
