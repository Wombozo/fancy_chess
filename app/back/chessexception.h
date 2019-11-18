#ifndef CHESSEXCEPTION_H
#define CHESSEXCEPTION_H

#include <exception>

typedef enum
{
    OUT_OF_BOARD,
    UNAUTHORIZED_PIECE_MOVE,
}chess_exception;

class ChessException: public std::exception
{
public:
    ChessException(chess_exception e);
};

#endif // CHESSEXCEPTION_H
