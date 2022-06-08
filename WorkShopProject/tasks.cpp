#include "tasks.h"
#include "ui_tasks.h"

Tasks::Tasks(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Tasks)
{
    ui->setupUi(this);

}

Tasks::~Tasks()
{
    delete ui;
}

void Tasks::on_pushButton_clicked()
{

    //az safe tasks be safe ezafe kardane task miravad



    hide();

    addtask=new AddTask();

    addtask->show();

}
