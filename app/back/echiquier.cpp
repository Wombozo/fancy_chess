#include "echiquier.h"

Echiquier echiquier;

Echiquier::Echiquier()
{
    Position a1('a',1);
    Position a2('a',2);
    Position a3('a',3);
    Position a4('a',4);
    Position a5('a',5);
    Position a6('a',6);
    Position a7('a',7);
    Position a8('a',8);

    Position b1('b',1);
    Position b2('b',2);
    Position b3('b',3);
    Position b4('b',4);
    Position b5('b',5);
    Position b6('b',6);
    Position b7('b',7);
    Position b8('b',8);

    Position c1('c',1);
    Position c2('c',2);
    Position c3('c',3);
    Position c4('c',4);
    Position c5('c',5);
    Position c6('c',6);
    Position c7('c',7);
    Position c8('c',8);

    Position d1('d',1);
    Position d2('d',2);
    Position d3('d',3);
    Position d4('d',4);
    Position d5('d',5);
    Position d6('d',6);
    Position d7('d',7);
    Position d8('d',8);

    Position e1('e',1);
    Position e2('e',2);
    Position e3('e',3);
    Position e4('e',4);
    Position e5('e',5);
    Position e6('e',6);
    Position e7('e',7);
    Position e8('e',8);

    Position f1('f',1);
    Position f2('f',2);
    Position f3('f',3);
    Position f4('f',4);
    Position f5('f',5);
    Position f6('f',6);
    Position f7('f',7);
    Position f8('f',8);

    Position g1('g',1);
    Position g2('g',2);
    Position g3('g',3);
    Position g4('g',4);
    Position g5('g',5);
    Position g6('g',6);
    Position g7('g',7);
    Position g8('g',8);

    Position h1('h',1);
    Position h2('h',2);
    Position h3('h',3);
    Position h4('h',4);
    Position h5('h',5);
    Position h6('h',6);
    Position h7('h',7);
    Position h8('h',8);

    positions = {
        a1, a2, a3, a4, a5, a6, a7, a8,
        b1, b2, b3, b4, b5, b6, b7, b8,
        c1, c2, c3, c4, c5, c6, c7, c8,
        d1, d2, d3, d4, d5, d6, d7, d8,
        e1, e2, e3, e4, e5, e6, e7, e8,
        f1, f2, f3, f4, f5, f6, f7, f8,
        g1, g2, g3, g4, g5, g6, g7, g8,
        h1, h2, h3, h4, h5, h6, h7, h8
    };

    for (auto &pos : positions)
    {
        pos.isFree = true;
    }
}
