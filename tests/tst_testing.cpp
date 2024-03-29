#include <QtTest>

#include "tour.h"
#include "cavalier.h"
#include "fou.h"
#include "roi.h"
#include "pion.h"
#include "dame.h"
#include "chessexception.h"
#include "position.h"
#include "echiquier.h"

// add necessary includes here

class Testing : public QObject
{
    Q_OBJECT

public:
    Testing();
    ~Testing();

private slots:
    void out_of_bounds();
    void disp_pos();
    void move_tour();
    void move_cavalier();
    void move_roi();
    void move_pion();
    void move_fou();
    void move_dame();
    void pieces_freed();
};

Testing::Testing()
{

}

Testing::~Testing()
{

}

#define CHECK_POS_OK(c,l) {Position p(c,l);QCOMPARE(p.check_exists(),0);}
#define CHECK_POS_EXC(c,l) {Position p(c,l);QVERIFY_EXCEPTION_THROWN(p.check_exists(),ChessException);}

void Testing::out_of_bounds()
{
    CHECK_POS_OK(a,1);
    CHECK_POS_OK(a,7);
    CHECK_POS_OK(d,4);
    CHECK_POS_OK(h,7);
    CHECK_POS_OK(h,8);

    CHECK_POS_EXC(a,0);
    CHECK_POS_EXC(-5,5);
    CHECK_POS_EXC(d,9);
    CHECK_POS_EXC(f,10);
    CHECK_POS_EXC(12,0);

}

#define QCOMPARE_POS_DISP(x,y,str) QCOMPARE(echiquier.positions.at( \
    static_cast<unsigned long>(x)-1).at( \
    static_cast<unsigned long>(y)-1)->display(),str);

#define OUT_OF_RANGE_POS_DISP(x,y,str) QVERIFY_EXCEPTION_THROWN(echiquier.positions.at( \
    static_cast<unsigned long>(x)-1).at(static_cast<unsigned long>(y)-1), \
    std::out_of_range);

void Testing::disp_pos()
{
    QCOMPARE_POS_DISP(1,1,"a1");
    QCOMPARE_POS_DISP(3,5,"c5");
    QCOMPARE_POS_DISP(4,1,"d1");
    QCOMPARE_POS_DISP(8,8,"h8");
    QCOMPARE_POS_DISP(6,7,"f7");
    OUT_OF_RANGE_POS_DISP(10,3,"a1");
    OUT_OF_RANGE_POS_DISP(2,13,"c8");
}

#define CHECK_TOUR_MOVE_OK(str,c,l) {QCOMPARE(echiquier.getPosition(str)->piece->move(c,l),0); QCOMPARE(echiquier.positions.at( \
    static_cast<unsigned long>(c) - 1).at(static_cast<unsigned long>(l) - 1)->piece->name,"R");}
#define CHECK_TOUR_MOVE_EXC(c,l) QVERIFY_EXCEPTION_THROWN(echiquier.getPosition("c3")->piece->move(c,l), ChessException);

void Testing::move_tour()
{
    echiquier.getPosition("c3")->piece = new Tour(WHITE, *echiquier.getPosition("c3"));
    echiquier.getPosition("c2")->piece = new Cavalier(WHITE, *echiquier.getPosition("c2"));
    echiquier.getPosition("e3")->piece = new Cavalier(WHITE, *echiquier.getPosition("e3"));
    echiquier.getPosition("c8")->piece = new Cavalier(BLACK, *echiquier.getPosition("c8"));

    CHECK_TOUR_MOVE_EXC(d,4);
    CHECK_TOUR_MOVE_EXC(a,1);
    CHECK_TOUR_MOVE_EXC(a,10);
    CHECK_TOUR_MOVE_EXC(c,2);
    CHECK_TOUR_MOVE_EXC(c,1);
    CHECK_TOUR_MOVE_EXC(e,3);
    CHECK_TOUR_MOVE_EXC(h,3);

    CHECK_TOUR_MOVE_OK("c3",d,3);
    CHECK_TOUR_MOVE_OK("d3",a,3);
    CHECK_TOUR_MOVE_OK("a3",a,8);
    CHECK_TOUR_MOVE_OK("a8",c,8);

    delete(echiquier.getPosition("c3")->piece); echiquier.getPosition("c3")->piece = nullptr;
    delete(echiquier.getPosition("c2")->piece); echiquier.getPosition("c2")->piece = nullptr;
    delete(echiquier.getPosition("e3")->piece); echiquier.getPosition("e3")->piece = nullptr;
    delete(echiquier.getPosition("c8")->piece); echiquier.getPosition("c8")->piece = nullptr;
}

#define CHECK_CAVALIER_MOVE_OK(str,c,l) {QCOMPARE(echiquier.getPosition(str)->piece->move(c,l),0); QCOMPARE(echiquier.positions.at( \
    static_cast<unsigned long>(c) - 1).at(static_cast<unsigned long>(l) - 1)->piece->name,"N");}

#define CHECK_CAVALIER_MOVE_EXC(c,l) QVERIFY_EXCEPTION_THROWN(echiquier.getPosition("f6")->piece->move(c,l), ChessException);


void Testing::move_cavalier()
{
    echiquier.getPosition("f6")->piece = new Cavalier(BLACK, *echiquier.getPosition("f6"));
    echiquier.getPosition("d8")->piece = new Tour(BLACK, *echiquier.getPosition("d8"));
    echiquier.getPosition("c3")->piece = new Tour(WHITE, *echiquier.getPosition("c3"));

    CHECK_CAVALIER_MOVE_EXC(f,5);
    CHECK_CAVALIER_MOVE_EXC(f,9);
    CHECK_CAVALIER_MOVE_EXC(g,6);
    CHECK_CAVALIER_MOVE_EXC(a,2);
    CHECK_CAVALIER_MOVE_EXC(b,1);
    CHECK_CAVALIER_MOVE_EXC(g,6);
    CHECK_CAVALIER_MOVE_EXC(d,8);

    CHECK_CAVALIER_MOVE_OK("f6",d,5);
    CHECK_CAVALIER_MOVE_OK("d5",b,4);
    CHECK_CAVALIER_MOVE_OK("b4",a,2);
    CHECK_CAVALIER_MOVE_OK("a2",c,3);

    delete(echiquier.getPosition("d8")->piece); echiquier.getPosition("d8")->piece = nullptr;
    delete(echiquier.getPosition("c3")->piece); echiquier.getPosition("c3")->piece = nullptr;
}

#define CHECK_ROI_MOVE_OK(str,c,l) {QCOMPARE(echiquier.getPosition(str)->piece->move(c,l),0); QCOMPARE(echiquier.positions.at( \
    static_cast<unsigned long>(c) - 1).at(static_cast<unsigned long>(l) - 1)->piece->name,"K");}

#define CHECK_ROI_MOVE_EXC(c,l) QVERIFY_EXCEPTION_THROWN(echiquier.getPosition("f6")->piece->move(c,l), ChessException);

void Testing::move_roi()
{
    echiquier.getPosition("f6")->piece = new Roi(WHITE, *echiquier.getPosition("f6"));
    echiquier.getPosition("g4")->piece = new Tour(BLACK, *echiquier.getPosition("g4"));
    echiquier.getPosition("f5")->piece = new Tour(WHITE, *echiquier.getPosition("f5"));

    CHECK_ROI_MOVE_EXC(a,1);
    CHECK_ROI_MOVE_EXC(h,10);
    CHECK_ROI_MOVE_EXC(e,4);
    CHECK_ROI_MOVE_EXC(f,5);

    CHECK_ROI_MOVE_OK("f6",f,7);
    CHECK_ROI_MOVE_OK("f7",g,6);
    CHECK_ROI_MOVE_OK("g6",g,5);
    CHECK_ROI_MOVE_OK("g5",g,4);

    delete(echiquier.getPosition("g4")->piece); echiquier.getPosition("g4")->piece = nullptr;
    delete(echiquier.getPosition("f5")->piece); echiquier.getPosition("f5")->piece = nullptr;
}

#define CHECK_PION_MOVE_OK(str,c,l) {QCOMPARE(echiquier.getPosition(str)->piece->move(c,l),0); QCOMPARE(echiquier.positions.at( \
    static_cast<unsigned long>(c) - 1).at(static_cast<unsigned long>(l) - 1)->piece->name,"");}

#define CHECK_PION_MOVE_EXC(str,c,l) QVERIFY_EXCEPTION_THROWN(echiquier.getPosition(str)->piece->move(c,l), ChessException);

void Testing::move_pion()
{
    echiquier.getPosition("e7")->piece = new Pion(BLACK, *echiquier.getPosition("e7"));
    echiquier.getPosition("e3")->piece = new Pion(WHITE, *echiquier.getPosition("e3"));
    echiquier.getPosition("d3")->piece = new Tour(WHITE, *echiquier.getPosition("d3"));

    CHECK_PION_MOVE_EXC("e7", e, 3);
    CHECK_PION_MOVE_EXC("e7", f, 7);
    CHECK_PION_MOVE_EXC("e7", f, 6);
    CHECK_PION_MOVE_EXC("e7", e, 2);
    CHECK_PION_MOVE_EXC("e7", e, 1);

    CHECK_PION_MOVE_OK("e7",e,6);
    QCOMPARE(echiquier.getPosition("e7")->piece, nullptr);
    delete(echiquier.getPosition("e6")->piece); echiquier.getPosition("e6")->piece = nullptr;

    echiquier.getPosition("e7")->piece = new Pion(BLACK, *echiquier.getPosition("e7"));
    CHECK_PION_MOVE_OK("e7",e,5);
    CHECK_PION_MOVE_OK("e5",e,4);
    CHECK_PION_MOVE_EXC("e4",e,3);
    CHECK_PION_MOVE_OK("e4",d,3);
    CHECK_PION_MOVE_OK("d3",d,2);

    delete(echiquier.getPosition("e3")->piece); echiquier.getPosition("e3")->piece = nullptr;
    delete(echiquier.getPosition("d2")->piece); echiquier.getPosition("d2")->piece = nullptr;
}

#define CHECK_FOU_MOVE_OK(str,c,l) {QCOMPARE(echiquier.getPosition(str)->piece->move(c,l),0); QCOMPARE(echiquier.positions.at( \
    static_cast<unsigned long>(c) - 1).at(static_cast<unsigned long>(l) - 1)->piece->name,"B");}

#define CHECK_FOU_MOVE_EXC(str,c,l) QVERIFY_EXCEPTION_THROWN(echiquier.getPosition(str)->piece->move(c,l), ChessException);

void Testing::move_fou()
{
    echiquier.getPosition("f6")->piece = new Fou(WHITE, *echiquier.getPosition("f6"));
    echiquier.getPosition("c3")->piece = new Pion(WHITE, *echiquier.getPosition("c3"));
    echiquier.getPosition("b6")->piece = new Tour(BLACK, *echiquier.getPosition("b6"));

    CHECK_FOU_MOVE_EXC("f6",f,5);
    CHECK_FOU_MOVE_EXC("f6",f,10);
    CHECK_FOU_MOVE_EXC("f6",c,6);
    CHECK_FOU_MOVE_EXC("f6",c,3);
    CHECK_FOU_MOVE_EXC("f6",b,2);

    CHECK_FOU_MOVE_OK("f6",e,7);
    CHECK_FOU_MOVE_OK("e7",b,4);
    CHECK_FOU_MOVE_EXC("b4",d,2);

    CHECK_FOU_MOVE_OK("b4",c,5);
    CHECK_FOU_MOVE_OK("c5",b,6);

    delete(echiquier.getPosition("c3")->piece); echiquier.getPosition("c3")->piece = nullptr;
    delete(echiquier.getPosition("b6")->piece); echiquier.getPosition("b6")->piece = nullptr;
}

#define CHECK_DAME_MOVE_OK(str,c,l) {QCOMPARE(echiquier.getPosition(str)->piece->move(c,l),0); QCOMPARE(echiquier.positions.at( \
    static_cast<unsigned long>(c) - 1).at(static_cast<unsigned long>(l) - 1)->piece->name,"Q");}

#define CHECK_DAME_MOVE_EXC(str,c,l) QVERIFY_EXCEPTION_THROWN(echiquier.getPosition(str)->piece->move(c,l), ChessException);

void Testing::move_dame()
{
    echiquier.getPosition("f6")->piece = new Dame(WHITE, *echiquier.getPosition("f6"));
    echiquier.getPosition("b2")->piece = new Fou(BLACK, *echiquier.getPosition("b2"));
    echiquier.getPosition("h3")->piece = new Cavalier(BLACK, *echiquier.getPosition("h3"));

    CHECK_DAME_MOVE_EXC("f6",h,1);
    CHECK_DAME_MOVE_EXC("f6",e,8);
    CHECK_DAME_MOVE_EXC("f6",a,4);
    CHECK_DAME_MOVE_EXC("f6",d,2);
    CHECK_DAME_MOVE_EXC("f6",a,1);
    CHECK_DAME_MOVE_EXC("f6",h,1);

    CHECK_DAME_MOVE_OK("f6",f,3);
    CHECK_DAME_MOVE_OK("f3",g,3);
    CHECK_DAME_MOVE_OK("g3",h,3);
    CHECK_DAME_MOVE_OK("h3",c,3);
    CHECK_DAME_MOVE_OK("c3",b,4);
    CHECK_DAME_MOVE_OK("b4",b,2);

    delete(echiquier.getPosition("b2")->piece); echiquier.getPosition("b2")->piece = nullptr;
}

void Testing::pieces_freed()
{
    for (auto &l : echiquier.positions)
    {
        for (auto &p : l)
        {
            QCOMPARE(p->piece, nullptr);
        }
    }
}

QTEST_APPLESS_MAIN(Testing)

#include "tst_testing.moc"
