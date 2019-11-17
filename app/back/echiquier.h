#ifndef ECHIQUIER_H
#define ECHIQUIER_H

#include <vector>
#include "position.h"

class Echiquier
{
public:
    std::vector<Position> positions;
public:
    Echiquier();
};

extern Echiquier echiquier;

#endif // ECHIQUIER_H
