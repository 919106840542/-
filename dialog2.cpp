#include "dialog2.h"
#include "ui_dialog2.h"
#include"person.h"
#include<QString>
#include<QLineEdit>
#include<QMessageBox>
Dialog2::Dialog2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog2)
{
    ui->setupUi(this);
    setWindowTitle("正在退票");
    setFixedSize(800,600);
    connect(ui->button1,&QPushButton::clicked,this,&Dialog2::deal1);//进行退票过程
    connect(ui->button2,&QPushButton::clicked,this,&Dialog2::sendslot1);//发出关闭退票窗口的信号
}

Dialog2::~Dialog2()
{
    delete ui;
}

void Dialog2::sendslot1()
{
    emit mysignal1();
}

void Dialog2::deal1()//将退票人的信息置为空
{
    QMessageBox::about(this,"正在退票","退票成功");
    str=ui->lineedit->text();//获取退票人的姓名或者身份证号
    //将退票人的所有信息清空
    for(int i=1;i<k3;i++)
    {
        if(person[i].name==str||person[i].idcard==str)
        {
            person[i].start="";
            person[i].end="";
            person[i].price=0;
            break;
        }
    }
    ui->lineedit->clear();//清除输入的信息
}
