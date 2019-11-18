#ifndef PIECE_H
#define PIECE_H

#include "position.h"

typedef enum
{
    WHITE,
    BLACK
}Colour;

class Piece
{
public:
    Position position;
    Colour colour;
public:
    Piece(Colour);
    virtual ~Piece();
    virtual int move(Position &);
};

#endif // PIECE_H
