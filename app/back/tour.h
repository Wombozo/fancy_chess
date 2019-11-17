#ifndef TOUR_H
#define TOUR_H

#include "piece.h"

class Tour : public Piece
{
public:
    Tour();
    virtual ~Tour();
    int move(Position &);
};

#endif // TOUR_H
