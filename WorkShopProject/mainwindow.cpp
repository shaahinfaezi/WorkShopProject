#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "calendar.h"
#include "tasks.h"

#include <QPixmap>



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setWindowTitle("To-Do List");


    QPixmap TASKS(":/rec /Icons/1737368_comment_description_outline_problem_task_icon.png");

    ui->label->setPixmap(TASKS.scaled(ui->label->width(),ui->label->height(),Qt::KeepAspectRatio));

    QPixmap CALENDAR(":/rec /Icons/3671721_calendar_icon.png");

    ui->label_2->setPixmap(CALENDAR.scaled(ui->label_2->width(),ui->label_2->height(),Qt::KeepAspectRatio));


}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{

    //az safe main be safe tasks miravad

    this->close();

    Tasks *tasks=Tasks::get_instance(this);

    tasks->show();


}

void MainWindow::on_pushButton_2_clicked()
{
    //az safe main be safe calendar miravad

    this->close();

    Calendar *calendar=new Calendar(this);

    calendar->show();


}
