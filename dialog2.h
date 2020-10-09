#ifndef DIALOG2_H
#define DIALOG2_H

#include <QDialog>
#include<QString>
namespace Ui {
class Dialog2;
}

class Dialog2 : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog2(QWidget *parent = 0);
    ~Dialog2();
    QString str;
    void sendslot1();//发出关闭退票窗口的信号
    void deal1();//将退票人的信息置为空
    int k3=1,j;
signals:
    void mysignal1();

private:
    Ui::Dialog2 *ui;
};

#endif // DIALOG2_H
