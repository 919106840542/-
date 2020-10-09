#ifndef DIALOGG_H
#define DIALOGG_H
#include<QString>
#include <QDialog>
#include"person.h"
#include"dialogxinxi.h"
namespace Ui {
class Dialogg;
}

class Dialogg : public QDialog
{
    Q_OBJECT

public:
    explicit Dialogg(QWidget *parent = 0);
    ~Dialogg();
    QString str5;
    void sendslott();
    int k2=1;
    Dialogxinxi w6;
    void close_1();//关闭展示信息的窗口
    void deal();//进行信息查询
signals:
    void mysignall();
private:
    Ui::Dialogg *ui;
};

#endif // DIALOGG_H
