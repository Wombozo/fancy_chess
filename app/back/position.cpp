#include "position.h"
#include "chessexception.h"
#include <iostream>

Position::Position()
{
}

Position::Position(char c, int l) : c(c), l(l)
{
}

int Position::check_exists() const
{
   if (c < 'a' || c > 'h' || l < 1 || l > 8)
        throw ChessException(OUT_OF_BOARD);
   return 0;
}

void Position::display()
{
    std::cout<<c<<l<<std::endl;
}
