#include "dialog.h"
#include "ui_dialog.h"
#include"person.h"
#include<QString>
#include<QMessageBox>
Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    setWindowTitle("正在购票");
    setFixedSize(800,600);
    connect(ui->button6,&QPushButton::clicked,this,&Dialog::Sendslot);//发出关闭购票窗口的信号
    connect(ui->button5,&QPushButton::clicked,this,&Dialog::Isbuying);//存入购票人的姓名和身份证号
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::Sendslot()
{
    emit Mysignal();
}

void Dialog::Isbuying()//输入姓名和身份证号并存入数组
{
    QMessageBox::about(this,"正在购票","购买成功");
    str3=ui->lineedit3->text();//获取购票人的姓名
    str4=ui->lineedit4->text();//获取购票人的身份证号
    person[k1-1].name=str3;//存入姓名信息
    person[k1-1].idcard=str4;//存入身份证号信息
    //清空输入的信息
    ui->lineedit3->clear();
    ui->lineedit4->clear();
}
