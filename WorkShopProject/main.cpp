#include "mainwindow.h"
#include <QDebug>
#include <QApplication>
#include "tasks.h"
#include "addtask.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();





    return a.exec();
}
