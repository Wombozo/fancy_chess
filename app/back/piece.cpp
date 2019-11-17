#include "piece.h"
#include "chessexception.h"
#include "echiquier.h"

Piece::Piece()
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
