#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialog.h"
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
    //this->ui->widget->fg = new test();
    //this->ui->widget->fg->fCoord();
    this->close();
}


void MainWindow::on_spinBox_3_valueChanged(int arg1)
{

    this->ui->widget->pointWidth = arg1;

}


void MainWindow::on_pushButton_2_clicked()
{
    this->ui->widget->fg = new cube();
    this->ui->widget->fg->fCoord();
}

void MainWindow::on_pushButton_3_clicked()
{
    this->ui->widget->fg = new squarePyramid();
    this->ui->widget->fg->fCoord();
}
/*
void MainWindow::on_pushButton_4_clicked()
{
    this->ui->widget->fg = new trianglePyramid();
    this->ui->widget->fg->fCoord();
}
*/

void MainWindow::on_pushButton_4_clicked()
{
    this->ui->widget->fg->valueUp();
}

void MainWindow::on_pushButton_5_clicked()
{
    this->ui->widget->fg->valueDown();
}
/*
void MainWindow::on_pushButton_6_clicked()
{
    this->ui->widget->fg = new line();
    this->ui->widget->fg->fCoord();
}*/

void MainWindow::on_spinBox_valueChanged(int arg1)
{
    this->ui->widget->mc = arg1;
}
