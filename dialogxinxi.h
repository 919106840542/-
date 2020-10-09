#ifndef DIALOGXINXI_H
#define DIALOGXINXI_H

#include <QDialog>
#include<QString>
namespace Ui {
class Dialogxinxi;
}

class Dialogxinxi : public QDialog
{
    Q_OBJECT

public:
    explicit Dialogxinxi(QWidget *parent = 0);
    ~Dialogxinxi();
    QString name_1,idcard_1,start_1,end_1,price_1;
    void fanhui();//发出关闭展示信息窗口的信号
signals:
    void mysignal_1();
public slots:
    void xinxichaxun();//展示要查询购票人的信息
private:
    Ui::Dialogxinxi *ui;
};

#endif // DIALOGXINXI_H
