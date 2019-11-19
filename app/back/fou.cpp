#include "fou.h"


#include "echiquier.h"

Fou::Fou(Colour col, Position pos) : Piece(col), position(pos)
{
    name = "F";
}

Fou::~Fou()
{
}

static bool isValidMove(int c, int l, Position position)
{

}

int Fou::move(int c, int l)
{
    Piece::move(c, l);

    // FOU GLOBAL MOVE
    if (isValidMove(c,l,position) == false)
        throw ChessException(UNAUTHORIZED_PIECE_MOVE);

    Piece *p = echiquier.positions.at(static_cast<unsigned long>(c)-1).at(static_cast<unsigned long>(l)-1)->piece;
    if (p != nullptr && p->colour == colour)
        throw ChessException(UNAUTHORIZED_PIECE_MOVE);
    if (p != nullptr && p->colour == !colour)
        delete echiquier.positions.at(static_cast<unsigned long>(c)-1).at(static_cast<unsigned long>(l)-1)->piece;

    // Area clear ?

    // Go for it
    echiquier.positions.at(static_cast<unsigned long>(c)-1).at(static_cast<unsigned long>(l)-1)->piece = dynamic_cast<Piece*>(this);
    echiquier.positions.at(static_cast<unsigned long>(position.coord[0] - 1)).at(
                static_cast<unsigned long>(position.coord[1]) - 1
            )->piece = nullptr;
    position = *echiquier.positions.at(static_cast<unsigned long>(c)-1).at(static_cast<unsigned long>(l)-1);
    return 0;
}

