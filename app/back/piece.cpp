#include "piece.h"
#include "chessexception.h"
#include "echiquier.h"

Piece::Piece(Colour col) : colour(col)
{

}

Piece::~Piece()
{
}

int Piece::move(int c, int l)
{
    try {
        Position pos(c, l);
        pos.check_exists();
    } catch(const ChessException &) {}
    return 0;
}
