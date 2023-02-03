#include "piece.h"

Piece::Piece()
{

}

void Piece::setImage(QImage im)
{
    this->image = im;
}

bool Piece::isOnStartPosition()
{
    return startPosition == curientPosition;
}
