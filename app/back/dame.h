#ifndef DAME_H
#define DAME_H

#include "piece.h"
#include "position.h"

class Dame : public Piece
{
public:
    Position position;
public:
    Dame(Colour, Position);
    virtual ~Dame();
    int move(int c, int l);
};


#endif // DAME_H
