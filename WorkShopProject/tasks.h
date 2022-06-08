#ifndef TASKS_H
#define TASKS_H

#include <QDialog>
#include "addtask.h"

namespace Ui {
class Tasks;
}

class Tasks : public QDialog
{
    Q_OBJECT

public:
    explicit Tasks(QWidget *parent = nullptr);
    ~Tasks();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Tasks *ui;

    AddTask *addtask;
};

#endif // TASKS_H
