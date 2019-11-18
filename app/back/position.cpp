#include "position.h"
#include "chessexception.h"
#include <iostream>

Position::Position()
{
}

Position::Position(int c, int l)
{
    coord[0] = c;
    coord[1] = l;
}

int Position::check_exists() const
{
   if (coord[0] < a || coord[0] > h || coord[1] < 1 || coord[1] > 8)
        throw ChessException(OUT_OF_BOARD);
   return 0;
}

char Position::parse_column(void)
{
    switch(coord[0])
    {
    case a:
        return 'a';
     case b:
        return 'b';
    case c:
        return 'c';
    case d:
        return 'd';
    case e:
        return 'e';
    case f:
        return 'f';
    default:
        throw ChessException(OUT_OF_BOARD);
    }
}

void Position::display()
{
    std::cout<<parse_column()<<coord[1]<<std::endl;
}
