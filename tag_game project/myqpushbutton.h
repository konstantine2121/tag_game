#ifndef MYQPUSHBUTTON_H
#define MYQPUSHBUTTON_H

#include <QPushButton>
class MyQPushButton :public QPushButton
{
     Q_OBJECT

public:

    MyQPushButton(QWidget * parent);
    MyQPushButton(const QString & text, QWidget * parent = 0);
    MyQPushButton(const QIcon & icon, const QString & text, QWidget * parent = 0);

signals:
    void clickedInd(int ind);

private:
    int index;
    int xStartPos;
    int yStartPos;
    void mousePressEvent(QMouseEvent * e);



};

#endif // MYQPUSHBUTTON_H
