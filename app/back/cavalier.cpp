#include "cavalier.h"
#include "echiquier.h"

Cavalier::Cavalier(Colour col, Position pos) : Piece(col), position(pos)
{
    name = "C";
}

Cavalier::~Cavalier()
{
}

int Cavalier::move(int c, int l)
{
    // CAVALIER GLOBAL MOVE
    if (position.coord[0] != c && position.coord[1] != l)
        throw ChessException(UNAUTHORIZED_PIECE_MOVE);

    Piece::move(c, l);

    Piece *p = echiquier.positions.at(static_cast<unsigned long>(c-1)).at(static_cast<unsigned long>(l-1))->piece;
    if (p != nullptr && p->colour == colour)
        throw ChessException(UNAUTHORIZED_PIECE_MOVE);



    return 0;
}
