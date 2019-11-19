#ifndef PION_H
#define PION_H

#include "piece.h"
#include "position.h"

class Pion : public Piece
{
public:
    Position position;
public:
    Pion(Colour, Position);
    virtual ~Pion();
    int move(int c, int l);
};


#endif // PION_H
