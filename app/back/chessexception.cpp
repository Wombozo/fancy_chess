#include "chessexception.h"
#include <iostream>

ChessException::ChessException(chess_exception e)
{
    switch (e)
    {
    case OUT_OF_BOARD:
        // std::cout<<"Exception : Out of board"<<std::endl;
        break;
    case UNAUTHORIZED_PIECE_MOVE:
       // std::cout<<"Exception : Unauthorized piece move"<<std::endl;
        break;
    }

}
