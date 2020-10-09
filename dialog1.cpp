#include "dialog1.h"
#include "ui_dialog1.h"
#include<QLineEdit>
Dialog1::Dialog1(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog1)
{
    ui->setupUi(this);
    setWindowTitle("查询余票");
    setFixedSize(800,600);
    connect(ui->button,&QPushButton::clicked,this,&Dialog1::sendslot);//发出关闭窗口的信号
}

Dialog1::~Dialog1()
{
    delete ui;
}

void Dialog1::chaxunyupiao()//显示余票数和价格
{
    ui->lineedit_1->setText(num);
    ui->lineedit_2->setText(price1);
    show();
}

void Dialog1::sendslot()
{
    emit mysignal();
}
