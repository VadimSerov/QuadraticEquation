#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "math.h"

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
    double a = ui->lineEdit->text().toDouble();
    double b = ui->lineEdit_2->text().toDouble();
    double c = ui->lineEdit_3->text().toDouble();
    double discriminant = b*b-4*a*c;
    double denominator = 2*a;
    if(discriminant>=0){
        double x1 = (-b+sqrt(discriminant))/denominator;
        double x2 = (-b-pow(discriminant,1/2))/denominator;
        ui->label_6->setText(QString::number(x1,'g',15));
        ui->label_7->setText(QString::number(x2,'g',15));
    } else {
        double re = (-b)/denominator;
        double im1 = sqrt(-discriminant)/denominator;
        double im2 = -sqrt(-discriminant)/denominator;
        ui->label_6->setText(QString::number(re,'g',15)+" re  +  "+QString::number(im1,'g',15)+" im ");
        ui->label_7->setText(QString::number(re,'g',15)+" re  +  "+QString::number(im2,'g',15)+" im ");

    }
}
