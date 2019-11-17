#include "tour.h"
#include "echiquier.h"

Tour::Tour()
{
}

Tour::~Tour()
{
}

int Tour::move(Position &new_pos)
{
    if (position.c != new_pos.c && position.l != new_pos.l)
        throw ChessException(UNAUTHORIZED_PIECE_MOVE);
    if (position.c == new_pos.c)
    {
        for (auto &pos : echiquier.positions)
        {
            if (pos.c == new_pos.c)
            {

            }
        }
    }
    Piece::move(new_pos);
    return 0;
}
