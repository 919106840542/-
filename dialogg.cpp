#include "dialogg.h"
#include "ui_dialogg.h"
#include"person.h"
#include"dialogxinxi.h"
#include<QDebug>
#include<QString>
#include<QLineEdit>
Dialogg::Dialogg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialogg)
{
    ui->setupUi(this);
    setWindowTitle("车票信息查询");
    setFixedSize(800,600);
    connect(ui->button7,&QPushButton::clicked,this,&Dialogg::deal);//进行信息查询
    connect(ui->button7,&QPushButton::clicked,&w6,&Dialogxinxi::xinxichaxun);//点击按钮展示查询到的信息
    connect(&w6,&Dialogxinxi::mysignal_1,this,Dialogg::close_1);//关闭展示信息的窗口
    connect(ui->button8,&QPushButton::clicked,this,&Dialogg::sendslott);//发出关闭信息查询的窗口
}

Dialogg::~Dialogg()
{
    delete ui;
}

void Dialogg::deal()//进行信息查询
{
    w6.show();
    str5=ui->lineedit5->text();//获取查询人的姓名或者身份证号
    //遍历所有人的信息进行查找
    for(int i=1;i<k2;i++)
    {
        if(person[i].name==str5||person[i].idcard==str5)
        {
            w6.name_1=person[i].name;
            w6.idcard_1=person[i].idcard;
            w6.start_1=person[i].start;
            w6.end_1=person[i].end;
            w6.price_1=QString::number(person[i].price);
            break;
        }
    }
    ui->lineedit5->clear();//清除输入的信息
}

void Dialogg::sendslott()
{
    emit mysignall();
}

void Dialogg::close_1()//关闭展示信息的窗口
{
    w6.close();
    this->show();
}
