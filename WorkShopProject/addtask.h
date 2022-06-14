#ifndef ADDTASK_H
#define ADDTASK_H

#include <QDialog>
#include <vector>

using std::vector;



namespace Ui {
class AddTask;
}

class AddTask : public QDialog
{
    Q_OBJECT

public:
    explicit AddTask(QWidget *parent = nullptr);
    explicit AddTask(QWidget *parent,int);
    explicit AddTask(QWidget *parent,vector<int>);


    ~AddTask();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

private:
    Ui::AddTask *ui;

    int current_row;

    int TaskArrayIndex;

    void print(int);

    vector<int> TaskArray;

};

#endif // ADDTASK_H
