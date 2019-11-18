#include "echiquier.h"

Echiquier echiquier;

Echiquier::Echiquier()
{
    Position *a1 = new Position(a,1);
    Position *a2 = new Position(a,2);
    Position *a3 = new Position(a,3);
    Position *a4 = new Position(a,4);
    Position *a5 = new Position(a,5);
    Position *a6 = new Position(a,6);
    Position *a7 = new Position(a,7);
    Position *a8 = new Position(a,8);

    Position *b1 = new Position(b,1);
    Position *b2 = new Position(b,2);
    Position *b3 = new Position(b,3);
    Position *b4 = new Position(b,4);
    Position *b5 = new Position(b,5);
    Position *b6 = new Position(b,6);
    Position *b7 = new Position(b,7);
    Position *b8 = new Position(b,8);

    Position *c1 = new Position(c,1);
    Position *c2 = new Position(c,2);
    Position *c3 = new Position(c,3);
    Position *c4 = new Position(c,4);
    Position *c5 = new Position(c,5);
    Position *c6 = new Position(c,6);
    Position *c7 = new Position(c,7);
    Position *c8 = new Position(c,8);

    Position *d1 = new Position(d,1);
    Position *d2 = new Position(d,2);
    Position *d3 = new Position(d,3);
    Position *d4 = new Position(d,4);
    Position *d5 = new Position(d,5);
    Position *d6 = new Position(d,6);
    Position *d7 = new Position(d,7);
    Position *d8 = new Position(d,8);

    Position *e1 = new Position(e,1);
    Position *e2 = new Position(e,2);
    Position *e3 = new Position(e,3);
    Position *e4 = new Position(e,4);
    Position *e5 = new Position(e,5);
    Position *e6 = new Position(e,6);
    Position *e7 = new Position(e,7);
    Position *e8 = new Position(e,8);

    Position *f1 = new Position(f,1);
    Position *f2 = new Position(f,2);
    Position *f3 = new Position(f,3);
    Position *f4 = new Position(f,4);
    Position *f5 = new Position(f,5);
    Position *f6 = new Position(f,6);
    Position *f7 = new Position(f,7);
    Position *f8 = new Position(f,8);

    Position *g1 = new Position(g,1);
    Position *g2 = new Position(g,2);
    Position *g3 = new Position(g,3);
    Position *g4 = new Position(g,4);
    Position *g5 = new Position(g,5);
    Position *g6 = new Position(g,6);
    Position *g7 = new Position(g,7);
    Position *g8 = new Position(g,8);

    Position *h1 = new Position(h,1);
    Position *h2 = new Position(h,2);
    Position *h3 = new Position(h,3);
    Position *h4 = new Position(h,4);
    Position *h5 = new Position(h,5);
    Position *h6 = new Position(h,6);
    Position *h7 = new Position(h,7);
    Position *h8 = new Position(h,8);

    positions = {
        {a1, a2, a3, a4, a5, a6, a7, a8},
        {b1, b2, b3, b4, b5, b6, b7, b8},
        {c1, c2, c3, c4, c5, c6, c7, c8},
        {d1, d2, d3, d4, d5, d6, d7, d8},
        {e1, e2, e3, e4, e5, e6, e7, e8},
        {f1, f2, f3, f4, f5, f6, f7, f8},
        {g1, g2, g3, g4, g5, g6, g7, g8},
        {h1, h2, h3, h4, h5, h6, h7, h8}
    };

}

Position *Echiquier::getPosition(std::string str)
{
    int c = str.at(0) - 96;
    int l = str.at(1) - 1;
    return positions.at(static_cast<unsigned long>(c)).at(static_cast<unsigned long>(l));
}
