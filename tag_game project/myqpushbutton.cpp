#include "myqpushbutton.h"

MyQPushButton::MyQPushButton(QWidget * parent)
    : QPushButton(parent)
{

}


MyQPushButton::MyQPushButton(const QString & text, QWidget * parent):QPushButton(text,parent)
{

}

MyQPushButton::MyQPushButton(const QIcon & icon, const QString & text, QWidget * parent):QPushButton(icon,text,parent)
{

}

void MyQPushButton::mousePressEvent(QMouseEvent * e)
{
   //emit clickedInd(this->index);
   // this->setGeometry(10,10,40,40);
}

