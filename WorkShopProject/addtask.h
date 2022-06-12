#ifndef ADDTASK_H
#define ADDTASK_H

#include <QDialog>



namespace Ui {
class AddTask;
}

class AddTask : public QDialog
{
    Q_OBJECT

public:
    explicit AddTask(QWidget *parent = nullptr);
    explicit AddTask(QWidget *parent,int);

    ~AddTask();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::AddTask *ui;

    int current_row;


};

#endif // ADDTASK_H
