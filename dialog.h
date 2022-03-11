#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <math.h>
namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    float getX();
    float getY();
    float getZ();

    void setX(float x);
    void setY(float y);
    void setZ(float z);
    ~Dialog();

private slots:
    void on_doubleSpinBox_2_valueChanged(double arg1);


    void on_doubleSpinBox_3_valueChanged(double arg1);


    void paintEvent(QPaintEvent *);
    void on_doubleSpinBox_valueChanged(double arg1);

private:
    Ui::Dialog *ui;
    float x,y,z;
};

#endif // DIALOG_H
