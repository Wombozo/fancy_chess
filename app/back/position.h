#ifndef POSITION_H
#define POSITION_H

#include "chessexception.h"

typedef enum
{
    a=1,
    b=2,
    c=3,
    d=4,
    e=5,
    f=6,
    g=7,
    h=8
}column;

class Position
{
public:
    int coord[2];
    bool isFree;
public:
    Position();
    Position(int, int);
    int check_exists(void) const;
    char parse_column(void);
    void display();
};

#endif // POSITION_H
