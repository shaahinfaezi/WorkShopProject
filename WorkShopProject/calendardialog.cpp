#include "calendardialog.h"
#include "ui_calendardialog.h"
#include "tasks.h"
#include <QMessageBox>
#include "addtask.h"
#include <QtDebug>



int temp_month,temp_year;

calendarDialog::calendarDialog(QWidget *parent,int day,int month,int year,int hour,int minute,int second,bool From_Calendar) :
    QDialog(parent),
    ui(new Ui::calendarDialog),day(day),month(month),year(year)
{


    temp_month=month;

    temp_year=year;

     ui->setupUi(this);

     Tasks *tasks=Tasks::get_instance(this);

     tasks->temp_DateTime=nullptr;

    if(!From_Calendar){

    ui->pushButton->setIconSize(*new QSize(65,65));
    ui->pushButton_2->setIconSize(*new QSize(65,65));

    ui->pushButton->setIcon(QIcon(":/rec /Icons/1814085_arrow_forward_next_right_icon.png"));
    ui->pushButton_2->setIcon(QIcon(":/rec /Icons/1814083_arrow_left_icon.png"));


    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);


    ui->tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);

     ui->tableWidget->horizontalHeader()->setVisible(true);


    print();

    ui->spinBox->setMinimum(0);

    ui->spinBox->setMaximum(23);

    ui->spinBox_2->setMinimum(0);

    ui->spinBox_2->setMaximum(59);

    ui->spinBox_3->setMinimum(0);

    ui->spinBox_3->setMaximum(59);

     ui->spinBox->setValue(hour);

     ui->spinBox_2->setValue(minute);

     ui->spinBox_3->setValue(second);

    }
    else{
       print();

       ui->spinBox->setValue(hour);

       ui->spinBox_2->setValue(minute);

       ui->spinBox_3->setValue(second);

       ui->spinBox->setEnabled(false);

       ui->spinBox_2->setEnabled(false);

       ui->spinBox_3->setEnabled(false);

       ui->pushButton->setEnabled(false);

       ui->pushButton_2->setEnabled(false);

       ui->pushButton_3->setEnabled(false);

       ui->pushButton->hide();

       ui->pushButton_2->hide();

       ui->pushButton_3->hide();

       ui->tableWidget->setEnabled(false);

    }

}



calendarDialog::~calendarDialog()
{
    delete ui;
}

void calendarDialog::print(){

    ui->tableWidget->clearContents();

    if((year%4==0 && year%100!=0) || year%400==0){

        number_of_days[1]=29;

    }

    int row,column;

    row=0;

    column=day_of_month(1,month,year);


    for(int i=1;i<=number_of_days[month-1];i++){

        QTableWidgetItem *table_item=new QTableWidgetItem(QString::number(i));

        ui->tableWidget->setItem(row,column,table_item);

        if(day==i && month==temp_month && year==temp_year){

            ui->tableWidget->selectionModel()->clearSelection();
            ui->tableWidget->selectionModel()->select(ui->tableWidget->model()->index(row,column),QItemSelectionModel::Select);
        }

        if(++column>6){

            column=0;
            row++;
        }

    }

    ui->label->setText(QString::fromUtf8(months[month-1].c_str()));

    ui->label_2->setText(QString::number(year));



}

int calendarDialog::day_of_month(int day,int month,int year){



       static int t[] = { 0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4 };

       if (month < 3) {

           year -= 1;

       } else {

           year -= 0;

       }

       return ( year + year/4 - year/100 + year/400 + t[month-1] + day) % 7;


}




void calendarDialog::on_pushButton_2_clicked()
{
    month--;

    if(month<1){

        month=12;
        year--;

    }

    print();



}

void calendarDialog::on_pushButton_clicked()
{
    month++;



    if(month>12){

        month=1;
        year++;

    }

    print();

}

void calendarDialog::on_pushButton_3_clicked()
{

    Tasks *tasks=Tasks::get_instance(this);

    if(ui->tableWidget->selectedItems().size()!=0 && ui->tableWidget->selectedItems().at(0)->text()!=""){



        //date va time ra temp save mikonim ta dar addtask be items add konim
        QDateTime *temp_DT=new QDateTime();

        QTime *temp_T=new QTime(ui->spinBox->value(),ui->spinBox_2->value(),ui->spinBox_3->value());

        temp_DT->setTime(*temp_T);

        QDate *temp_D=new QDate(year,month,ui->tableWidget->selectedItems().at(0)->text().toInt());

        temp_DT->setDate(*temp_D);

        tasks->temp_DateTime=temp_DT;


        this->hide();





    }
    else{

              QMessageBox::warning(this,"Warning","Please select a date.");

    }






}



