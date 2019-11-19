#include "dame.h"
#include "echiquier.h"

#include <algorithm>

Dame::Dame(Colour col, Position pos) : Piece(col), position(pos)
{
    name = "Q";
}

Dame::~Dame()
{
}

static bool isValidMove(int c, int l, Position position)
{
    int max_c = std::max(c, position.coord[0]);
    int min_c = std::min(c, position.coord[0]);
    int max_l = std::max(l, position.coord[1]);
    int min_l = std::min(l, position.coord[1]);
    if (max_c-min_c == max_l-min_l  || c == position.coord[0] || l == position.coord[1])
        return true;
    return false;
}

int Dame::move(int c, int l)
{
    Piece::move(c, l);

    // DAME GLOBAL MOVE

    if (isValidMove(c,l,position) == false)
        throw ChessException(UNAUTHORIZED_PIECE_MOVE);

    Piece *p = echiquier.positions.at(static_cast<unsigned long>(c)-1).at(static_cast<unsigned long>(l)-1)->piece;
    if (p != nullptr && p->colour == colour)
        throw ChessException(UNAUTHORIZED_PIECE_MOVE);

    // Area clear ?
    // LINES
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

    // DIAGS
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
