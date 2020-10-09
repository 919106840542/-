#include "Mainwindow.h"
#include "ui_Mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("火车票模拟购票系统");
    setFixedSize(800,600);//设置窗口大小
    for(int i=1;i<=9;i++)
    {
        p[i]=chushizhi++;
    }//相邻两站之间车票的价格
    connect(ui->button1,&QPushButton::clicked,this,&MainWindow::operate);//输入起点站和终点站查询余票
    connect(ui->button1,&QPushButton::clicked,&w4,&Dialog1::chaxunyupiao);//把余票数和价格显示在窗口上
    connect(&w4,&Dialog1::mysignal,this,&MainWindow::yupiao);//关闭查询余票窗口
    connect(ui->button2,&QPushButton::clicked,this,&MainWindow::goupiao);//打开购票窗口，存入购票人的起点站，终点站和价格
    connect(&w2,&Dialog::Mysignal,this,&MainWindow::close);//关闭购票窗口
    connect(ui->button3,&QPushButton::clicked,this,&MainWindow::chaxun);//打开信息查询窗口
    connect(&w3,&Dialogg::mysignall,this,&MainWindow::guanbi);//关闭信息查询窗口
    connect(ui->button4,&QPushButton::clicked,this,&MainWindow::tuipiao);//打开退票窗口
    connect(&w5,&Dialog2::mysignal1,this,&MainWindow::guanbi1);//关闭退票窗口
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::goupiao(){//购票窗口打开
    w2.show();
    person[k].start=str1;//设置起点站
    person[k].end=str2;//设置终点站
    person[k].price=price1;//设置价格
    k++;//人数增加
    w2.k1++;
    w3.k2++;
    w5.k3++;
}

void MainWindow::close(){//购票窗口关闭
    w2.close();
    this->show();
}

void MainWindow::operate(){//计算余票数和价格
    str1=ui->lineedit1->text();//读取起点站信息
    str2=ui->lineedit2->text();//读取终点站信息
    //转为char型数组
    QByteArray ba1=str1.toLatin1();
    char *c1=ba1.data();
    QByteArray ba2=str2.toLatin1();
    char *c2=ba2.data();
    //复制信息
    strcpy(point[k].startpoint,c1);
    strcpy(point[k].endpoint,c2);
    //读取数组第二位或第三位信息
    point[k].start1=point[k].startpoint[1]-48;
    if(point[k].endpoint[2]=='\0')
        point[k].end1=point[k].endpoint[1]-48;
    else
        point[k].end1=(point[k].endpoint[1]-48)*10+point[k].endpoint[2]-48;
    num=10;//总票数设为10
    price1=0;//价格设为0
    //遍历之前购买人的信息来获得余票数
    for(int j=1;j<k;j++)
    {
        if(point[k].start1>=point[j].end1||point[k].end1<=point[j].start1||person[j].start=="")
        continue;
        else
        num--;
    }
    //获取价格
    for(int j=point[k].start1;j<point[k].end1;j++)
        price1+=p[j];
    //余票数不能为负数
    if(num<0)
        num=0;
    w4.num=QString::number(num);//准备显示余票数
    w4.price1=QString::number(price1);//准备显示价格
    w4.show();
    ui->lineedit1->clear();//清空信息
    ui->lineedit2->clear();//清空信息
}

void MainWindow::chaxun()//信息查询窗口打开
{
    w3.show();
}

void MainWindow::guanbi()//信息查询窗口关闭
{
    w3.close();
    this->show();
}

void MainWindow::yupiao()//查询余票窗口关闭
{
    w4.close();
    this->show();
}

void MainWindow::tuipiao()//退票窗口打开
{
    w5.show();
}

void MainWindow::guanbi1()//退票窗口关闭
{
    w5.close();
    this->show();
}

