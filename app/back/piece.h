#ifndef PIECE_H
#define PIECE_H

#include <string>

typedef enum
{
    WHITE,
    BLACK
}Colour;

class Piece
{
public:
    Colour colour;
    std::string name;
public:
    Piece(Colour);
    virtual ~Piece();
    virtual int move(int c, int l);
};

#endif // PIECE_H
