#include "tour.h"
#include "echiquier.h"

Tour::Tour(Colour col, Position *pos) : Piece(col), position(pos)
{
    name = "T";
}

Tour::~Tour()
{
}

int Tour::move(int c, int l)
{
    if (position->coord[0] != c && position->coord[1] != l)
        throw ChessException(UNAUTHORIZED_PIECE_MOVE);

    Piece::move(c, l);
    return 0;
}
