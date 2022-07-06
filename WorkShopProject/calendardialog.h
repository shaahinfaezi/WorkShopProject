#ifndef CALENDARDIALOG_H
#define CALENDARDIALOG_H


#include <QDialog>
#include <string>
#include <QDateTime>

#include "mainwindow.h"

using std::string;



namespace Ui {
class calendarDialog;
}




class calendarDialog : public QDialog
{
    Q_OBJECT

    //esme mah ha
    string months[12]={"January","February","March","April","May","June","July","August","September","October","November","December"};

    //tedad rooz dar har mah
    int number_of_days[12]={31,28,31,30,31,30,31,31,30,31,30,31};

public:
    explicit calendarDialog(QWidget *parent,

    int day=QDateTime::currentDateTime().date().day(),

    int month=QDateTime::currentDateTime().date().month(),

    int year=QDateTime::currentDateTime().date().year(),

    int hour=0,int minute=0,int second=0,bool From_Calendar=false
 );
    ~calendarDialog();

    friend class Calendar;



private slots:


    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::calendarDialog *ui;

    int day;

    int month;

    int year;

    //tabe i baraye mohasebe avalin rooze yek mah va sal
    int day_of_month(int,int);

    ////namayeshe calendar dialog
    void print();




};

#endif // CALENDARDIALOG_H
