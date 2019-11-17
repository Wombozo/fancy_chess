#ifndef POSITION_H
#define POSITION_H

#include "chessexception.h"

class Position
{
public:
    char c;
    int l;
    bool isFree;
public:
    Position();
    Position(char, int);
    int check_exists(void) const;
    void display();
};

#endif // POSITION_H
