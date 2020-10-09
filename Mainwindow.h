#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include"dialog.h"
#include"person.h"
#include"dialog1.h"
#include"dialog2.h"
#include"dialogxinxi.h"
#include"dialogg.h"
#include <QMainWindow>
#include<QPushButton>
#include<QString>
#include<QDialog>
#include <QLineEdit>
#include<QThread>
#include<QDebug>
#include<QPaintEvent>
#include<QPixmap>
#include<QPainter>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    Dialog w2;//购票窗口
    Dialogg w3;//信息查询窗口
    Dialog1 w4;//查询余票窗口
    Dialog2 w5;//退票窗口
    void close();//购票窗口关闭
    void goupiao();//购票窗口打开
    void operate();//计算余票数和价格
    void chaxun();//信息查询窗口打开
    void yupiao();//查询余票窗口关闭
    void tuipiao();//退票窗口打开
    void guanbi();//信息查询窗口关闭
    void guanbi1();//退票窗口关闭
    struct Point{
        int start1;
        int end1;
        char startpoint[3];
        char endpoint[3];
    };
    Point point[50];//临时处理起点站和终点站而设置的
    int chushizhi=50,p[11];
    QString a,b,s,t;
    int k=1,num,price1;
    QString str1;
    QString str2;
private slots:
private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
