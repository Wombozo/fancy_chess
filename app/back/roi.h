#ifndef ROI_H
#define ROI_H

#include "piece.h"
#include "position.h"

class Roi : public Piece
{
public:
    Position position;
public:
    Roi(Colour, Position);
    virtual ~Roi();
    int move(int c, int l);
};

#endif // ROI_H
