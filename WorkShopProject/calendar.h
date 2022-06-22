#ifndef CALENDAR_H
#define CALENDAR_H

#include <QDialog>

#include "calendardialog.h"

namespace Ui {
class Calendar;
}

class Calendar : public QDialog
{
    Q_OBJECT

public:

    explicit Calendar(QWidget *parent = nullptr);
    ~Calendar();


private slots:

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_tableWidget_cellDoubleClicked(int row, int column);

private:
    Ui::Calendar *ui;


    //namayeshe calendar
    void print();

    //pointeri az CalendarDialog ke betavan az member hash estefade kard
    calendarDialog *CalendarDialog;


};

#endif // CALENDAR_H
