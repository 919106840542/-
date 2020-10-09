#include "dialogxinxi.h"
#include "ui_dialogxinxi.h"
#include"person.h"
#include<QLineEdit>
#include<QString>
Dialogxinxi::Dialogxinxi(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialogxinxi)
{
    ui->setupUi(this);
    setWindowTitle("车票信息查询");
    setFixedSize(800,600);
    connect(ui->button,&QPushButton::clicked,this,&Dialogxinxi::fanhui);//发出返回上一级的信号
}

Dialogxinxi::~Dialogxinxi()
{
    delete ui;
}

void Dialogxinxi::fanhui()
{
    emit mysignal_1();
}

void Dialogxinxi::xinxichaxun()//展示要查询购票人的信息
{
    ui->lineedit1->setText(name_1);
    ui->lineedit2->setText(idcard_1);
    ui->lineedit3->setText(start_1);
    ui->lineedit4->setText(end_1);
    ui->lineedit5->setText(price_1);
    show();
}
