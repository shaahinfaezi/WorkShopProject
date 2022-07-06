#include "mainwindow.h"
#include "tasks.h"
#include "addtask.h"


#include <QApplication>



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setWindowIcon(QIcon(":/rec /Icons/1622833_checkmark_done_exam_list_pencil_icon.png"));
    MainWindow w;
    w.show();



    return a.exec();
}
