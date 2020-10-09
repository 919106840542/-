#ifndef PERSON_H
#define PERSON_H
#include<QString>
class Person
{
public:
    Person();
    QString name;
    QString idcard;
    QString start;
    QString end;
    int price;
};
extern Person person[50];
#endif // PERSON_H
