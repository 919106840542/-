#ifndef DIALOG1_H
#define DIALOG1_H

#include <QDialog>
#include<QString>
namespace Ui {
class Dialog1;
}

class Dialog1 : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog1(QWidget *parent = 0);
    ~Dialog1();
    QString num,price1;
    void sendslot();
signals:
    void mysignal();
public slots:
    void chaxunyupiao();//显示余票数和价格
private:
    Ui::Dialog1 *ui;
};

#endif // DIALOG1_H
