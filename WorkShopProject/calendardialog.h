#ifndef CALENDARDIALOG_H
#define CALENDARDIALOG_H

#include <QDialog>
#include <string>
#include <QDateTime>


using std::string;

namespace Ui {
class calendarDialog;
}

class calendarDialog : public QDialog
{
    Q_OBJECT

public:
    explicit calendarDialog(QWidget *parent,

    int day=1,

    int month=QDateTime::currentDateTime().date().month(),

    int year=QDateTime::currentDateTime().date().year(),

    int hour=0,int minute=0,int second=0
 );
    ~calendarDialog();

private slots:


    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::calendarDialog *ui;

    int day;

    int month;

    int year;

    int day_of_month(int,int,int);

    void print();


};

#endif // CALENDARDIALOG_H
