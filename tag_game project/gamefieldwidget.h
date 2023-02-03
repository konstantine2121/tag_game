#ifndef GAMEFIELDWIDGET_H
#define GAMEFIELDWIDGET_H

#include <QtWidgets>
#include "piece.h"

class gameFieldWidget : public QWidget
{
    Q_OBJECT

public:
    explicit gameFieldWidget(QWidget *parent = 0);

    enum nearFieldIsEpmty
    {
        none,
        left,
        right,
        up,
        down
    };

public slots:

    void startNewGame();

signals:

    void gameOver();

private:

    bool gameIsOver;

    QPoint fieldSize;
    QPoint emptyField;

    void randomizeField();

    QList <Piece *> pieces;

    void paintEvent(QPaintEvent * event);
    void mousePressEvent(QMouseEvent * event);

    void movePiece(int posInList);
    int getNearEmptyField(int posInList);
    void checkGameOver();

};

#endif // GAMEFIELDWIDGET_H
