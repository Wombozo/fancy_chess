#ifndef CAVALIER_H
#define CAVALIER_H

#include "piece.h"
#include "position.h"

class Cavalier : public Piece
{
public:
    Position position;
public:
    Cavalier(Colour, Position);
    virtual ~Cavalier();
    int move(int c, int l);
};

#endif // CAVALIER_H
