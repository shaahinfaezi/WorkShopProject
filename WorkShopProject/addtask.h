//in class baraye add kardan,edit kardan va neshoon dadane task haye yek rooz hengamike az calendar be in safhe miaim estefade mishavad

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

    //index itemi az list ke select shode
    int current_row;

    //shomarende i baraye neshoon dadan list task haye sabt shode dar yek rooze khas (baraye vaghti az calendar be in safe miaim)
    unsigned int TaskArrayIndex;

    //tabe baraye por kardan field ha vaghti edit anjam mishavad ya az calendar be task oomadim(yek rooz select shode)
    void print(int);

    vector<int> TaskArray;

};

#endif // ADDTASK_H
