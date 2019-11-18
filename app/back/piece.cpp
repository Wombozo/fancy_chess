#include "piece.h"
#include "chessexception.h"
#include "echiquier.h"

Piece::Piece(Colour col) : colour(col)
{

}

Piece::~Piece()
{
}

int Piece::move(Position &pos)
{
    try {
        pos.check_exists();
        position = pos;
        pos.isFree = false;
    } catch(const ChessException &) {}
    return 0;
}
