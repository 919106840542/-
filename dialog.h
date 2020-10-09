#ifndef DIALOG_H
#define DIALOG_H
#include <QDialog>
#include<QString>
#include"person.h"
namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();
    void Sendslot();//发射关闭购票窗口的信号
    void Isbuying();//输入姓名和身份证号并存入数组
    QString str3;
    QString str4;
    int k1=1;
signals:
    void Mysignal();
private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H
