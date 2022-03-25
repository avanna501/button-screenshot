#ifndef HEADER_H
#define HEADER_H

#include <QPushButton>
#include <QCheckBox>
#include <iostream>
#include <QString>
#include <QObject>

using namespace std;

class C : public QObject
{
    Q_OBJECT
    int counter=0;
    bool h;

    public:
        QPushButton * p;
        QCheckBox * box;
        string * t;

    public slots:
        void setValue(bool click)
        {
            counter++;
            if (box->isChecked())
                p->setText(QString("the counter is %1").arg(counter));
  //              t="the counter is "+QString::number(counter);
            else
                p->setText("The box is not checked");
        }

 /*       void whenHidden(bool isChecked())
        {

        }*/
};

//+ QString::number(counter)
#endif // HEADER_H
