#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{

    //az safe main be safe tasks miravad

    hide();
    tasks=Tasks::get_instance(this);
    tasks->show();
}

void MainWindow::on_pushButton_2_clicked()
{
    //az safe main be safe calendar miravad

    hide();
    calendar=new Calendar(this);
    calendar->show();


}
