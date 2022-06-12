#ifndef TASKS_H
#define TASKS_H

#include <QDialog>
#include <QTimer>
#include <iostream>
#include <QDateTime>
#include <vector>



#include "item.h"
#include "addtask.h"


using std::vector;

namespace Ui {
class Tasks;
}

class Tasks : public QDialog
{
    Q_OBJECT

public:

   static Tasks* get_instance(QWidget *parent = nullptr); //singleton pattern baraye task


   vector<item*> items; //liste item ha

   QDateTime *temp_DateTime; //temporary datetime baraye inke motmaen shavim ke karbar task ra save mikonad


    Ui::Tasks *ui;

    ~Tasks();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

    void Due();

private:


    QTimer *Timer;


    static Tasks* instance;


    explicit Tasks(QWidget *parent = nullptr);



    AddTask *addtask;




};

#endif // TASKS_H
