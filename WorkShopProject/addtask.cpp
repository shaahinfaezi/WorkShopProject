#include "addtask.h"
#include "ui_addtask.h"
#include "tasks.h"
#include "ui_tasks.h"
#include "item.h"
#include "calendardialog.h"

#include <string>
#include <vector>
#include <QString>
#include <QMessageBox>
#include <QtDebug>



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
    //vaghti add zade shode
    ui->setupUi(this);
    current_row=-2;
}

AddTask::AddTask(QWidget *parent,int current_row) :
    QDialog(parent),
    ui(new Ui::AddTask),
    current_row(current_row)

{
    //vaghti domke edit zade shode
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

        string priority=ui->comboBox->currentText().toLocal8Bit().constData();


        Tasks *tasks=Tasks::get_instance(this);


            if(!empty_string_check(title) && !empty_string_check(description) && tasks->temp_DateTime!=nullptr && !empty_string_check(priority) && current_row==-2){
            //save kardane task (dokme add zade shode)



            int last_index=tasks->items.size();

            tasks->items.push_back(new item(title,description,priority,tasks->temp_DateTime->date().day(),tasks->temp_DateTime->date().month(),tasks->temp_DateTime->date().year(),tasks->temp_DateTime->time().hour(),tasks->temp_DateTime->time().minute(),tasks->temp_DateTime->time().second()));

            //add kardane item be listWidget

            //matne list (text formatting)

             int width=tasks->ui->listWidget->minimumWidth();

             QFont myFont(tasks->ui->listWidget->font());

             QString str(QString::fromUtf8(title.c_str()));

             QFontMetrics fm(myFont);

             int title_width=fm.horizontalAdvance(str);

             QString timeString = QString("%1:%2:%3")
               .arg(tasks->temp_DateTime->time().hour(), 2, 10, QChar('0'))
               .arg(tasks->temp_DateTime->time().minute(), 2, 10, QChar('0'))
               .arg(tasks->temp_DateTime->time().second(), 2, 10, QChar('0'));



            QString text=QString::fromUtf8(tasks->items[last_index]->get_title().c_str())+QString(((2*width)/10)-title_width,' ')+QString::number(tasks->items[last_index]->get_month())+"/"+QString::number(tasks->items[last_index]->get_day())+"/"+QString::number(tasks->items[last_index]->get_year())+QString(width/20,' ')+timeString;



            //item list(baraye icon az resource file estefade shode)

            QListWidgetItem *lItem=new QListWidgetItem(QIcon(":/rec /Icons/211717_circle_icon.png"),text);



            tasks->ui->listWidget->addItem(lItem);


            //bargashtan be safe tasks
            this->close();

            tasks->show();
        }





            else if(!empty_string_check(title) && !empty_string_check(description)  && tasks->temp_DateTime!=nullptr && !empty_string_check(priority) && current_row!=-2){
                //edit kardane task




                tasks->items.at(current_row)->set_title(title);

                tasks->items.at(current_row)->set_description(description);

                tasks->items.at(current_row)->set_priority(priority);

                tasks->items.at(current_row)->set_day(tasks->temp_DateTime->date().day());

                tasks->items.at(current_row)->set_month(tasks->temp_DateTime->date().month());

                tasks->items.at(current_row)->set_year(tasks->temp_DateTime->date().year());

                tasks->items.at(current_row)->set_hour(tasks->temp_DateTime->time().hour());

                tasks->items.at(current_row)->set_minute(tasks->temp_DateTime->time().minute());

                tasks->items.at(current_row)->set_second(tasks->temp_DateTime->time().second());


                //edit kardane item too listWidget


                int width=tasks->ui->listWidget->minimumWidth();

                QFont myFont(tasks->ui->listWidget->font());

                QString str(QString::fromUtf8(title.c_str()));

                QFontMetrics fm(myFont);

                int title_width=fm.horizontalAdvance(str);

                QString timeString = QString("%1:%2:%3")
                  .arg(tasks->temp_DateTime->time().hour(), 2, 10, QChar('0'))
                  .arg(tasks->temp_DateTime->time().minute(), 2, 10, QChar('0'))
                  .arg(tasks->temp_DateTime->time().second(), 2, 10, QChar('0'));



                QString text=QString::fromUtf8(tasks->items[current_row]->get_title().c_str())+QString(((2*width)/10)-title_width,' ')+QString::number(tasks->items[current_row]->get_month())+"/"+QString::number(tasks->items[current_row]->get_day())+"/"+QString::number(tasks->items[current_row]->get_year())+QString(width/20,' ')+timeString;

                tasks->ui->listWidget->currentItem()->setText(text);


                 //bargashtan be safe tasks
                this->close();

                tasks->show();


        }



            else{

            //error baraye vaghtike field ha kamel por nashode

                QMessageBox::warning(this,"Warning","Please enter all the information needed.");



            }




}

void AddTask::on_pushButton_3_clicked()
{
    if(current_row==-2){


    calendarDialog *Calendar=new calendarDialog(this);

    Calendar->setModal(true);

    Calendar->exec();

    }
    else{

        Tasks *tasks=Tasks::get_instance();

        calendarDialog *Calendar=new calendarDialog(this,tasks->items.at(current_row)->get_day(),tasks->items.at(current_row)->get_month(),tasks->items.at(current_row)->get_year(),tasks->items.at(current_row)->get_hour(),tasks->items.at(current_row)->get_minute(),tasks->items.at(current_row)->get_second());

        Calendar->setModal(true);

        Calendar->exec();



    }



}
