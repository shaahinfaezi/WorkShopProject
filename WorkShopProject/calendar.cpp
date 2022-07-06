#include "calendar.h"
#include "ui_calendar.h"
#include "mainwindow.h"
#include "tasks.h"
#include "vector"

#include <QDateTime>
#include <QMessageBox>

using std::vector;




Calendar::Calendar(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Calendar)
{
    ui->setupUi(this);
    setWindowTitle("Calendar");

    ui->pushButton->setIcon(QIcon(":/rec /Icons/back.png"));

    ui->pushButton_2->setIconSize(*new QSize(65,65));
    ui->pushButton_3->setIconSize(*new QSize(65,65));

    ui->pushButton_2->setIcon(QIcon(":/rec /Icons/1814085_arrow_forward_next_right_icon.png"));
    ui->pushButton_3->setIcon(QIcon(":/rec /Icons/1814083_arrow_left_icon.png"));


    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);


    ui->tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);

    CalendarDialog=new calendarDialog(this);

    ui->tableWidget->horizontalHeader()->setVisible(true);

    print();
}


Calendar::~Calendar()
{
    delete ui;
    delete CalendarDialog;
}


void Calendar::print(){


    Tasks *tasks=Tasks::get_instance(this);

    ui->tableWidget->clearContents();

    //check kardane sal kabise
    if((CalendarDialog->year%4==0 && CalendarDialog->year%100!=0) || CalendarDialog->year%400==0){

        CalendarDialog->number_of_days[1]=29;

    }

    int row,column;

    row=0;

    column=CalendarDialog->day_of_month(CalendarDialog->month,CalendarDialog->year);//rooze aval oon mah va sal



    for(int i=1;i<=CalendarDialog->number_of_days[CalendarDialog->month-1];i++){

        QTableWidgetItem *table_item=new QTableWidgetItem(QString::number(i));

        ui->tableWidget->setItem(row,column,table_item);

        //check kardane inke taski dar in rooz hast ya na
        for(int j=0;j<int(tasks->items.size());j++){


            if(tasks->items.at(j)->get_day()==i && tasks->items.at(j)->get_month()==CalendarDialog->month &&tasks->items.at(j)->get_year()==CalendarDialog->year){



                ui->tableWidget->item(row,column)->setBackground(QBrush(Qt::green));


            }
        }

        if(++column>6){

            column=0;
            row++;
        }

    }

    ui->label->setText(QString::fromUtf8(CalendarDialog->months[CalendarDialog->month-1].c_str()));

    ui->label_2->setText(QString::number(CalendarDialog->year));




}



void Calendar::on_pushButton_clicked()
{
    //bargashtan be safe aval
    this->hide();

    MainWindow *mainwindow=new MainWindow(this);

    mainwindow->show();
}

void Calendar::on_pushButton_2_clicked()
{

    //mahe baad

    CalendarDialog->month++;



     if(CalendarDialog->month>12){

        CalendarDialog-> month=1;
         CalendarDialog->year++;

     }

     print();


}

void Calendar::on_pushButton_3_clicked()
{


    //mahe ghabl
    CalendarDialog-> month--;

       if(CalendarDialog->month<1){

           CalendarDialog->month=12;
           CalendarDialog->year--;

       }

       print();


}

void Calendar::on_tableWidget_cellDoubleClicked(int row, int column)
{

    //etelaate task haye sabt shode dar in rooz
    Tasks *tasks=Tasks::get_instance(this);
     vector<int> TaskArray;

    for(int i=0;i<int(tasks->items.size());i++){


        if(tasks->items.at(i)->get_day()==ui->tableWidget->item(row,column)->text().toInt() && tasks->items.at(i)->get_month()==CalendarDialog->month &&tasks->items.at(i)->get_year()==CalendarDialog->year){


            TaskArray.push_back(i);


        }
    }

    if(TaskArray.size()!=0){
    this->hide();

    AddTask *addTask=new AddTask(this,TaskArray);

    addTask->show();

}
    else{

    QMessageBox::information(this,"Info","There is no task for the day\nEnjoy!");


    }

}
