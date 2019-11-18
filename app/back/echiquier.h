#ifndef ECHIQUIER_H
#define ECHIQUIER_H

#include <vector>
#include "position.h"

typedef enum
{
    BLANCS,
    NOIRS
}Trait;

class Echiquier
{
public:
    std::vector<Position> positions;
    Trait trait = BLANCS;
public:
    Echiquier();
};

extern Echiquier echiquier;

#endif // ECHIQUIER_H
