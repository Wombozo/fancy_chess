#include "pion.h"

#include "echiquier.h"

#include <algorithm>

Pion::Pion(Colour col, Position pos) : Piece(col), position(pos)
{
    name = "";
}

Pion::~Pion()
{
}

static bool isValidMove(int c, int l, Position position, Colour col, Piece *p)
{
    if (col == WHITE)
    {
        if (l == position.coord[1] + 1 && c == position.coord[0] && p == nullptr)
            return true;
        if (position.coord[1] == 2 && l == 4 && p == nullptr && echiquier.positions.at(static_cast<unsigned long>(c)-1).at(2)->piece == nullptr)
            return true;
        if (p != nullptr && p->colour == !col && l == position.coord[1]+1 && std::abs(c - position.coord[0]) == 1)
        {
            delete p;
            return true;
        }
    }
    else if (col == BLACK)
    {
        if (l == position.coord[1] -1 && c == position.coord[0] && p == nullptr)
            return true;
        if (position.coord[1] == 7 && l == 5 && p == nullptr && echiquier.positions.at(static_cast<unsigned long>(c)-1).at(7)->piece == nullptr)
            return true;
        if (p != nullptr && p->colour == !col && l == position.coord[1] - 1 && std::abs(c - position.coord[0]) == 1)
        {
            delete p;
            return true;
        }
    }
    return false;
}

int Pion::move(int c, int l)
{
    Piece::move(c, l);

    Piece *p = echiquier.positions.at(static_cast<unsigned long>(c-1)).at(static_cast<unsigned long>(l-1))->piece;
    if (p != nullptr && p->colour == colour)
        throw ChessException(UNAUTHORIZED_PIECE_MOVE);

    // Pion GLOBAL MOVE
    if (isValidMove(c,l, position, colour, p) == false)
        throw ChessException(UNAUTHORIZED_PIECE_MOVE);

    //TODO: CHESS

    // Go gor it
    echiquier.positions.at(static_cast<unsigned long>(c)-1).at(static_cast<unsigned long>(l)-1)->piece = dynamic_cast<Piece*>(this);
    echiquier.positions.at(static_cast<unsigned long>(position.coord[0] - 1)).at(
                static_cast<unsigned long>(position.coord[1]) - 1
            )->piece = nullptr;
    position = *echiquier.positions.at(static_cast<unsigned long>(c)-1).at(static_cast<unsigned long>(l)-1);


    return 0;
}
