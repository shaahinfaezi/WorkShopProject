#include "tasks.h"
#include "ui_tasks.h"
#include "mainwindow.h"
#include <QThread>
#include <QDebug>
#include <QDateTime>



using std::vector;




Tasks * Tasks::instance=nullptr;



Tasks::Tasks(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Tasks)
{

    ui->setupUi(this);


     ui->listWidget->setIconSize(*new QSize(35,35));

     ui->pushButton_5->setIcon(QIcon(":/rec /Icons/back.png"));

     Timer=new QTimer(this);

    connect(Timer,SIGNAL(timeout()),this,SLOT(Due()));


    Timer->start(1000);

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

void Tasks::on_pushButton_4_clicked()
{
    //done va undone mikonad task ro
    if(ui->listWidget->count()>0 && ui->listWidget->currentItem()!=nullptr && !items.at(ui->listWidget->currentRow())->get_done()){



    ui->listWidget->currentItem()->setIcon(QIcon(":/rec /Icons/1930264_check_complete_done_green_success_icon (1).png"));

    items.at(ui->listWidget->currentRow())->set_done(true);

     }
    else if(ui->listWidget->count()>0 && ui->listWidget->currentItem()!=nullptr && items.at(ui->listWidget->currentRow())->get_done()){


        ui->listWidget->currentItem()->setIcon(QIcon(":/rec /Icons/211717_circle_icon.png"));

        items.at(ui->listWidget->currentRow())->set_done(false);

    }
}

void Tasks::Due(){

    int current_time=QDateTime::currentDateTime().toTime_t();

    int seconds_inDay =24*60*60;


    for(int i=0;i<items.size();i++)      {

        QDate D=*new QDate(items.at(i)->get_year(),items.at(i)->get_month(),items.at(i)->get_day());

        QTime T=*new QTime(items.at(i)->get_hour(),items.at(i)->get_minute(),items.at(i)->get_second());

        QDateTime DT=*new QDateTime(D,T);

        int due_time=DT.toTime_t();

        if(!items.at(i)->get_done()){





        if(current_time>due_time){


            ui->listWidget->item(i)->setBackground(Qt::red);

        }
        else if(due_time - current_time<seconds_inDay){

            ui->listWidget->item(i)->setBackground(Qt::yellow);


        }

        else{
            ui->listWidget->item(i)->setBackground(QColor(146, 182, 177));
        }


    }

        else{
            ui->listWidget->item(i)->setBackground(QColor(146, 182, 177));
        }


    }







}



void Tasks::on_pushButton_5_clicked()
{

    this->hide();

    MainWindow *mainwindow=new MainWindow(this);

    mainwindow->show();


}
