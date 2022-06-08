#include "addtask.h"
#include "ui_addtask.h"
#include "tasks.h"

AddTask::AddTask(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddTask)
{
    ui->setupUi(this);
}

AddTask::~AddTask()
{
    delete ui;
}

void AddTask::on_pushButton_2_clicked()
{

    //az safe ezafe kardane task be safe tasks barmigardad

    this->close();
    Tasks *tasks=new Tasks(this);

    tasks->show();


}
