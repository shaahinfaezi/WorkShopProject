#include "calendar.h"
#include "ui_calendar.h"
#include "mainwindow.h"
#include "tasks.h"




Calendar::Calendar(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Calendar)
{
    ui->setupUi(this);


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
}

void Calendar::print(){


    Tasks *tasks=Tasks::get_instance(this);

    ui->tableWidget->clearContents();

    if((CalendarDialog->year%4==0 && CalendarDialog->year%100!=0) || CalendarDialog->year%400==0){

        CalendarDialog->number_of_days[1]=29;

    }

    int row,column;

    row=0;

    column=CalendarDialog->day_of_month(1,CalendarDialog->month,CalendarDialog->year);


    for(int i=1;i<=CalendarDialog->number_of_days[CalendarDialog->month-1];i++){

        QTableWidgetItem *table_item=new QTableWidgetItem(QString::number(i));

        ui->tableWidget->setItem(row,column,table_item);



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
    this->hide();

    MainWindow *mainwindow=new MainWindow(this);

    mainwindow->show();
}

void Calendar::on_pushButton_2_clicked()
{



    CalendarDialog->month++;



     if(CalendarDialog->month>12){

        CalendarDialog-> month=1;
         CalendarDialog->year++;

     }

     print();


}

void Calendar::on_pushButton_3_clicked()
{



    CalendarDialog-> month--;

       if(CalendarDialog->month<1){

           CalendarDialog->month=12;
           CalendarDialog->year--;

       }

       print();


}

void Calendar::on_tableWidget_cellDoubleClicked(int row, int column)
{





}
