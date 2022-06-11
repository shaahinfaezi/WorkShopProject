#include "addtask.h"
#include "ui_addtask.h"
#include "tasks.h"
#include "ui_tasks.h"
#include "item.h"

#include <string>
#include <vector>
#include <QString>
#include <QMessageBox>



using std::vector;

using std::all_of;

using std::string;



bool empty_string_check(string s){//check mikonad ke string ha khali nabashand

    if(all_of(s.begin(),s.end(),isspace)||s.empty()){
        return true;
    }
    else{
        return false;
    }

}

AddTask::AddTask(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddTask)
{
    ui->setupUi(this);
    current_row=-2;
}

AddTask::AddTask(QWidget *parent,int current_row) :
    QDialog(parent),
    ui(new Ui::AddTask),
    current_row(current_row)

{
    ui->setupUi(this);

    Tasks *tasks=Tasks::get_instance(this);



    ui->lineEdit->setText(QString::fromUtf8(tasks->items[current_row]->get_title().c_str()));

    ui->textEdit->setText(QString::fromUtf8(tasks->items[current_row]->get_description().c_str()));

    //calendar

    ui->comboBox->setCurrentText(QString::fromUtf8(tasks->items[current_row]->get_priority().c_str()));

}

AddTask::~AddTask()
{
    delete ui;
}

void AddTask::on_pushButton_2_clicked()
{

    //az safe ezafe kardane task be safe tasks barmigardad

    this->close();
    Tasks *tasks=Tasks::get_instance(this);

    tasks->show();


}




void AddTask::on_pushButton_clicked()
{


    string title=ui->lineEdit->text().toLocal8Bit().constData();

    string description=ui->textEdit->toPlainText().toLocal8Bit().constData();

    //calandar

    string priority=ui->comboBox->currentText().toLocal8Bit().constData();


        Tasks *tasks=Tasks::get_instance(this);


            if(!empty_string_check(title) && !empty_string_check(description)          && !empty_string_check(priority) && current_row==-2){
            //save kardane task (dokme add zade shode)



            int last_index=tasks->items.size();

            tasks->items.push_back(new item(title,description,priority,11,6,2022,12,56,10));

            //add kardane item be listWidget

            tasks->ui->listWidget->addItem(QString::fromUtf8(title.c_str())+"                "+QString::number(tasks->items[last_index]->get_month())+"/"+QString::number(tasks->items[last_index]->get_day())+"/"+QString::number(tasks->items[last_index]->get_year()));


            //bargashtan be safe tasks
            this->close();

            tasks->show();
        }





            else if(!empty_string_check(title) && !empty_string_check(description)          && !empty_string_check(priority) && current_row!=-2){
                //edit kardane task




                tasks->items.at(current_row)->set_title(title);

                tasks->items.at(current_row)->set_description(description);

                tasks->items.at(current_row)->set_priority(priority);

                tasks->items.at(current_row)->set_day(12);

                tasks->items.at(current_row)->set_month(6);

                tasks->items.at(current_row)->set_year(2022);

                tasks->items.at(current_row)->set_hour(12);

                tasks->items.at(current_row)->set_minute(56);

                tasks->items.at(current_row)->set_second(10);



                //edit kardane item too listWidget


                tasks->ui->listWidget->currentItem()->setText(QString::fromUtf8(tasks->items[current_row]->get_title().c_str())+"                "+QString::number(tasks->items[current_row]->get_month())+"/"+QString::number(tasks->items[current_row]->get_day())+"/"+QString::number(tasks->items[current_row]->get_year()));




                 //bargashtan be safe tasks
                this->close();

                tasks->show();


        }







            else{

            //error baraye vaghtike field ha kamel por nashode

                QMessageBox::warning(this,"Warning","Please enter all the information needed.");



            }














}
