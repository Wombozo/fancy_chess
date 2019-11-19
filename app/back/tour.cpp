#include "tour.h"
#include "echiquier.h"

#include <algorithm>

Tour::Tour(Colour col, Position pos) : Piece(col), position(pos)
{
    name = "T";
}

Tour::~Tour()
{
}

int Tour::move(int c, int l)
{
    // TOUR GLOBAL MOVE
    if (position.coord[0] != c && position.coord[1] != l)
        throw ChessException(UNAUTHORIZED_PIECE_MOVE);

    Piece::move(c, l);

    Piece *p = echiquier.positions.at(static_cast<unsigned long>(c)-1).at(static_cast<unsigned long>(l)-1)->piece;
    if (p != nullptr && p->colour == colour)
        throw ChessException(UNAUTHORIZED_PIECE_MOVE);

    // Area clear ?
    int max, min;
    if (position.coord[1] == l)
    {
        max = std::max(position.coord[0], c);
        min = std::min(position.coord[0], c);
        for (auto &lines : echiquier.positions)
        {
            if (lines.at(static_cast<unsigned long>(l)-1)->coord[0] > min && lines.at(static_cast<unsigned long>(l)-1)->coord[0] < max)
            {
                if (lines.at(static_cast<unsigned long>(l)-1)->piece != nullptr)
                    throw ChessException(UNAUTHORIZED_PIECE_MOVE);
            }

        }
    }
    else
    {
        max = std::max(position.coord[1], l);
        min = std::min(position.coord[1], l);
        for (auto &pos : echiquier.positions.at(static_cast<unsigned long>(c)-1))
        {
            if (pos->coord[1] > min && pos->coord[1] < max)
            {
                if (pos->piece != nullptr)
                    throw ChessException(UNAUTHORIZED_PIECE_MOVE);
            }
        }
    }

    //TODO: CHESS

    // Go gor it
    if (p != nullptr && p->colour == !colour)
        delete echiquier.positions.at(static_cast<unsigned long>(c)-1).at(static_cast<unsigned long>(l)-1)->piece;
    echiquier.positions.at(static_cast<unsigned long>(c)-1).at(static_cast<unsigned long>(l)-1)->piece = dynamic_cast<Piece*>(this);
    echiquier.positions.at(static_cast<unsigned long>(position.coord[0] - 1)).at(
                static_cast<unsigned long>(position.coord[1]) - 1
            )->piece = nullptr;
    position = *echiquier.positions.at(static_cast<unsigned long>(c)-1).at(static_cast<unsigned long>(l)-1);

    return 0;
}
