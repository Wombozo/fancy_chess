#include "fou.h"


#include "echiquier.h"

Fou::Fou(Colour col, Position pos) : Piece(col), position(pos)
{
    name = "B";
}

Fou::~Fou()
{
}

static bool isValidMove(int c, int l, Position position)
{
    int max_c = std::max(c, position.coord[0]);
    int min_c = std::min(c, position.coord[0]);
    int max_l = std::max(l, position.coord[1]);
    int min_l = std::min(l, position.coord[1]);
    if (max_c-min_c == max_l-min_l)
        return true;
    return false;
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

    // Area clear ?
    for (auto &lines : echiquier.positions)
    {
        for (auto &pos : lines)
        {
            int max_c = std::max(c, position.coord[0]);
            int min_c = std::min(c, position.coord[0]);
            int max_l = std::max(l, position.coord[1]);
            int min_l = std::min(l, position.coord[1]);
            int max_ci = std::max(pos->coord[0], position.coord[0]);
            int min_ci = std::min(pos->coord[0], position.coord[0]);
            int max_li = std::max(pos->coord[1], position.coord[1]);
            int min_li = std::min(pos->coord[1], position.coord[1]);
            if (pos->coord[0] > min_c && pos->coord[0] < max_c && pos->coord[1] > min_l && pos->coord[1] < max_l && max_ci-min_ci == max_li-min_li)
            {
                if (pos->piece != nullptr)
                    throw ChessException(UNAUTHORIZED_PIECE_MOVE);
            }
        }
    }

    if (p != nullptr && p->colour == !colour)
        delete echiquier.positions.at(static_cast<unsigned long>(c)-1).at(static_cast<unsigned long>(l)-1)->piece;

    // Go for it
    echiquier.positions.at(static_cast<unsigned long>(c)-1).at(static_cast<unsigned long>(l)-1)->piece = dynamic_cast<Piece*>(this);
    echiquier.positions.at(static_cast<unsigned long>(position.coord[0] - 1)).at(
                static_cast<unsigned long>(position.coord[1]) - 1
            )->piece = nullptr;
    position = *echiquier.positions.at(static_cast<unsigned long>(c)-1).at(static_cast<unsigned long>(l)-1);
    return 0;
}

