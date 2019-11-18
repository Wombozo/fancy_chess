#include "tour.h"
#include "echiquier.h"

Tour::Tour(Colour col) : Piece(col)
{
}

Tour::~Tour()
{
}

int Tour::move(Position &new_pos)
{
    if (position.coord[0] != new_pos.coord[0] && position.coord[1] != new_pos.coord[1])
        throw ChessException(UNAUTHORIZED_PIECE_MOVE);

    Piece::move(new_pos);
    return 0;
}
