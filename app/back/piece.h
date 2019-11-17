#ifndef PIECE_H
#define PIECE_H

#include "position.h"

class Piece
{
public:
    Position position;
public:
    Piece();
    virtual ~Piece();
    virtual int move(Position &);
};

#endif // PIECE_H
