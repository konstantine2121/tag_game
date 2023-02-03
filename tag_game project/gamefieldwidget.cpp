#include "gamefieldwidget.h"
#include <QDebug>

gameFieldWidget::gameFieldWidget(QWidget *parent) :
    QWidget(parent),
    gameIsOver(true),
    fieldSize(QPoint(4,4))

{
    int n = fieldSize.x()*fieldSize.y()-1;
    int k=0;
    for (int i=0;i<fieldSize.y();i++)
    {
        for (int j=0;j<fieldSize.x();j++)
        {
            if (k>=n) return;

            Piece * onePiece = new Piece;

            onePiece->text=QString::number(k+1);
            onePiece->startPosition= QPoint(j,i);
            onePiece->curientPosition = onePiece->startPosition;

            pieces.append(onePiece);

            k++;
        }
    }



}

void gameFieldWidget::startNewGame()
{
    gameIsOver = false;
    randomizeField();
    this->update();
}


void gameFieldWidget::randomizeField()
{
    qDebug()<<"randomize is working";

    //упорядочить в начальное положение
    for (int i=0;i<pieces.count();i++)
    {
        pieces[i]->curientPosition =  pieces[i]->startPosition;
    }
    //Сделать кучу случайных движений
    emptyField.setX(fieldSize.x()-1);
    emptyField.setY(fieldSize.y()-1);

    int nn = 300;


    for (int i=0;i<nn;i++)
    {
        QList <int> list;

        QPoint leftPos =emptyField;
        leftPos.rx()--;
        QPoint rightPos=emptyField;;
        rightPos.rx()++;
        QPoint upPos=emptyField;;
        upPos.ry()--;
        QPoint downPos=emptyField;
        downPos.ry()++;


        //проверить их на совпадение с вылетом за границы контейнера

        if (leftPos.x() >= 0)
        {
            for (int k=0;k<pieces.count();k++)
            {
                if (pieces[k]->curientPosition == leftPos)
                {
                    list.append(k);
                    break;
                }
            }

        }

        if ( rightPos.x() < this->fieldSize.x())
        {
            for (int k=0;k<pieces.count();k++)
            {
                if (pieces[k]->curientPosition == rightPos)
                {
                    list.append(k);
                    break;
                }
            }
        }

        if (upPos.y() >=0)
        {
            for (int k=0;k<pieces.count();k++)
            {
                if (pieces[k]->curientPosition == upPos)
                {
                    list.append(k);
                    break;
                }
            }
        }

        if (downPos.y() <  this->fieldSize.y())
        {
            for (int k=0;k<pieces.count();k++)
            {
                if (pieces[k]->curientPosition == downPos)
                {
                    list.append(k);
                    break;
                }
            }
        }

        int rand = qrand() % list.count();
        //exchange
        QPoint ch = emptyField;

        emptyField = pieces[list[rand]]->curientPosition;
        pieces[list[rand]]->curientPosition = ch;

        list.clear();

    }

}

void gameFieldWidget::movePiece(int posInList)
{
    int dir = getNearEmptyField(posInList);

    qDebug()<<"dir "<<QString::number(dir);

    if (dir != none)
    {
        QPoint ch = emptyField;
        emptyField = pieces[posInList]->curientPosition;
        pieces[posInList]->curientPosition = ch;
    }
}


int gameFieldWidget::getNearEmptyField(int posInList)
{
    qDebug()<<"getNearEmptyField pos "<<QString::number(posInList);
    QPoint curPos =  pieces[posInList]->curientPosition;

    QPoint leftPos =curPos;
    leftPos.rx()--;
    QPoint rightPos=curPos;;
    rightPos.rx()++;
    QPoint upPos=curPos;;
    upPos.ry()--;
    QPoint downPos=curPos;
    downPos.ry()++;


    //проверить их на совпадение с вылетом за границы контейнера

    if (leftPos.x() >= 0)
    {
        if (leftPos == emptyField)
            return left;
    }

    if ( rightPos.x() < this->fieldSize.x())
    {
        if (rightPos == emptyField)
            return right;
    }

    if (upPos.y() >=0)
    {
        if (upPos == emptyField)
            return up;
    }

    if (downPos.y() <  this->fieldSize.y())
    {
        if (downPos == emptyField)
            return down;
    }

    return none;
}


void gameFieldWidget::paintEvent(QPaintEvent * event)
{

    QPainter painter(this);
    painter.setBrush(Qt::lightGray);
    painter.fillRect(this->rect(),Qt::lightGray);

    int cellSizeX = this->width()/ fieldSize.x();
    int cellSizeY = this->height() /fieldSize.y();

    int frameSize =2;

    for(int i=0;i<pieces.count();i++)
    {
        QRect rect1(pieces[i]->curientPosition.x()*cellSizeX+frameSize,
                    pieces[i]->curientPosition.y()*cellSizeY+frameSize,
                    cellSizeX-frameSize*2,
                    cellSizeY-frameSize*2);

        painter.fillRect(rect1,Qt::gray);
        painter.setPen(Qt::blue);
        painter.setFont(QFont("Arial", 14));

        painter.drawText(rect1, Qt::AlignCenter,pieces[i]->text );

    }
}


void gameFieldWidget::mousePressEvent(QMouseEvent * event)
{
    if (gameIsOver) return;

    int cellSizeX = this->width()/ fieldSize.x();
    int cellSizeY = this->height() /fieldSize.y();

    int i = event->x()/cellSizeX;
    int j = event->y()/cellSizeY;

    QPoint tpoint(i,j);

    if (tpoint == emptyField) return;

    int numOfCell =0;

    for (int k=0;k<pieces.count();k++)
    {
        if (pieces[k]->curientPosition == tpoint)
        {
            numOfCell = k;
            break;
        }
    }

    movePiece(numOfCell);
    checkGameOver();

    this->update();

}


void gameFieldWidget::checkGameOver()
{
    for(int i=0;i<pieces.count();i++)
    {
        if (! pieces[i]->isOnStartPosition()) return;
    }

    gameIsOver = true;
    emit gameOver();
}
