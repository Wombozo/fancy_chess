#include <QtTest>
#include "tour.h"
#include "cavalier.h"
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
    static_cast<unsigned long>(c) - 1).at(static_cast<unsigned long>(l) - 1)->piece->name,"T");}
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

    QCOMPARE(echiquier.getPosition("c3")->piece, nullptr);
    QCOMPARE(echiquier.getPosition("d3")->piece, nullptr);
    QCOMPARE(echiquier.getPosition("a3")->piece, nullptr);
    QCOMPARE(echiquier.getPosition("a8")->piece, nullptr);

    delete(echiquier.getPosition("c3")->piece);
    delete(echiquier.getPosition("c2")->piece);
    delete(echiquier.getPosition("e3")->piece);
    delete(echiquier.getPosition("c8")->piece);
}

#define CHECK_CAVALIER_MOVE_OK(str,c,l) {QCOMPARE(echiquier.getPosition(str)->piece->move(c,l),0); QCOMPARE(echiquier.positions.at( \
    static_cast<unsigned long>(c) - 1).at(static_cast<unsigned long>(l) - 1)->piece->name,"C");}

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

    QCOMPARE(echiquier.getPosition("f6")->piece, nullptr);
    QCOMPARE(echiquier.getPosition("d5")->piece, nullptr);
    QCOMPARE(echiquier.getPosition("b4")->piece, nullptr);
    QCOMPARE(echiquier.getPosition("a2")->piece, nullptr);

    delete(echiquier.getPosition("d8"));
    delete(echiquier.getPosition("c3"));
}


QTEST_APPLESS_MAIN(Testing)

#include "tst_testing.moc"
