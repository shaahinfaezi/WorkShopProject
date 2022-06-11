#include "tasks.h"
#include "ui_tasks.h"
#include <QThread>
#include <QDebug>



using std::vector;




Tasks * Tasks::instance=nullptr;



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

    addtask=new AddTask(this);

    addtask->show();




}

Tasks* Tasks::get_instance(QWidget *parent){//singleton pattern baraye task


    if(instance==nullptr){

        instance=new Tasks(parent);

    }

    return instance;

}





void Tasks::on_pushButton_3_clicked()
{
    if(ui->listWidget->count()>0 && ui->listWidget->currentItem()!=nullptr){
    //remove iteme select shode az items

    items.erase(items.begin()+ui->listWidget->currentRow());


    //delete iteme select shode az listWidget
    qDeleteAll(ui->listWidget->selectedItems());

    }

}


void Tasks::on_pushButton_2_clicked()
{
    //az safe tasks be safe edit kardane task miravad

if(ui->listWidget->count()>0 && ui->listWidget->currentItem()!=nullptr){

    hide();

    addtask=new AddTask(this,ui->listWidget->currentRow());

    addtask->show();

}

}
