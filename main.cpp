#include "mainwindow.h"
#include <QApplication>
#include <tabulation.h>
#include <QtGui>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    tabulation *abulation = new tabulation();
    w.show();

    return a.exec();
}
