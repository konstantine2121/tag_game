#ifndef PIECE_H
#define PIECE_H

#include <QObject>
#include <QPoint>
#include <QImage>

class Piece
{
public:
    Piece();
    QPoint startPosition;
    QPoint curientPosition;    
    QImage image;
    QString text;

    void setImage(QImage im);
    bool isOnStartPosition();
};

#endif // PIECE_H
