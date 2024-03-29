#include "cavalier.h"
#include "echiquier.h"

Cavalier::Cavalier(Colour col, Position pos) : Piece(col), position(pos)
{
    name = "N";
}

Cavalier::~Cavalier()
{
}

static bool isValidMove(int c, int l, Position position)
{
    bool result = false;
    int max_c = std::max(c, position.coord[0]);
    int min_c = std::min(c, position.coord[0]);
    int max_l = std::max(l, position.coord[1]);
    int min_l = std::min(l, position.coord[1]);
    if ((std::abs(max_c - min_c) == 2 && std::abs(max_l - min_l) == 1) || (std::abs(max_c - min_c) == 1 && std::abs(max_l - min_l) == 2))
        result = true;
    return result;
}

int Cavalier::move(int c, int l)
{
    Piece::move(c, l);

    // CAVALIER GLOBAL MOVE
    if (isValidMove(c,l, position) == false)
        throw ChessException(UNAUTHORIZED_PIECE_MOVE);

    Piece *p = echiquier.positions.at(static_cast<unsigned long>(c-1)).at(static_cast<unsigned long>(l-1))->piece;
    if (p != nullptr && p->colour == colour)
        throw ChessException(UNAUTHORIZED_PIECE_MOVE);
    if (p != nullptr && p->colour == !colour)
        delete echiquier.positions.at(static_cast<unsigned long>(c)-1).at(static_cast<unsigned long>(l)-1)->piece;

    //TODO: CHESS

    // Go gor it
    echiquier.positions.at(static_cast<unsigned long>(c)-1).at(static_cast<unsigned long>(l)-1)->piece = dynamic_cast<Piece*>(this);
    echiquier.positions.at(static_cast<unsigned long>(position.coord[0] - 1)).at(
                static_cast<unsigned long>(position.coord[1]) - 1
            )->piece = nullptr;
    position = *echiquier.positions.at(static_cast<unsigned long>(c)-1).at(static_cast<unsigned long>(l)-1);


    return 0;
}
