#include "mainwindow.h"
#include "dop.h"
#include <global.h>
#include <QApplication>

int global::glob = 0;
QString global::logos = "";
QString global::change1 = "";
//int MainWindow::glob = 0;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
