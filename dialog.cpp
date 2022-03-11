#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{

    ui->setupUi(this);
}

Dialog::~Dialog()
{

    delete ui;
}

void Dialog::on_doubleSpinBox_2_valueChanged(double arg1)
{

   this->x = (float) arg1;
}

void Dialog::on_doubleSpinBox_3_valueChanged(double arg1)
{
    this->y =  (float) arg1;
}

void Dialog::paintEvent(QPaintEvent *) {
    ui->doubleSpinBox->setValue(z);
    ui->doubleSpinBox_2->setValue(x);
    ui->doubleSpinBox_3->setValue(y);
}

void Dialog::on_doubleSpinBox_valueChanged(double arg1)
{

    this->z = (float) arg1;
}

float Dialog::getX(){

    return x;
}
float Dialog::getY(){
    return y;
}
float Dialog::getZ(){
    return z;
}

void Dialog::setX(float x){
    this->x = x;
}

void Dialog::setY(float y){
    this->y = y;
}

void Dialog::setZ(float z){
    this->z = z;
}

