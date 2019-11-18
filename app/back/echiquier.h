#ifndef ECHIQUIER_H
#define ECHIQUIER_H

#include <vector>
#include <string>

#include "position.h"

typedef enum
{
    BLANCS,
    NOIRS
}Trait;

class Echiquier
{
public:
    std::vector<std::vector<Position*>> positions;
    Trait trait = BLANCS;
public:
    Echiquier();
    Position *getPosition(std::string);
};

extern Echiquier echiquier;

#endif // ECHIQUIER_H
