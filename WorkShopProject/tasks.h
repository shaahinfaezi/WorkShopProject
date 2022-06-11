#ifndef TASKS_H
#define TASKS_H

#include <QDialog>
#include "addtask.h"
#include <iostream>

#include "item.h"

#include <vector>

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


    Ui::Tasks *ui;

    ~Tasks();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

private:



    static Tasks* instance;


    explicit Tasks(QWidget *parent = nullptr);



    AddTask *addtask;




};

#endif // TASKS_H
