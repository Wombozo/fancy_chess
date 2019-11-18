#ifndef TOUR_H
#define TOUR_H

#include "piece.h"
#include "position.h"

class Tour : public Piece
{
public:
    Position *position;
public:
    Tour(Colour, Position*);
    virtual ~Tour();
    int move(int c, int l);
};

#endif // TOUR_H
