#ifndef FOU_H
#define FOU_H

#include "piece.h"
#include "position.h"

class Fou : public Piece
{
public:
    Position position;
public:
    Fou(Colour, Position);
    virtual ~Fou();
    int move(int c, int l);
};

#endif // FOU_H
