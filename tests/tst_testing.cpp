#include <QtTest>
#include "tour.h"
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

#define QCOMPARE_POS_DISP(x,y,str) QCOMPARE(echiquier.positions.at(x).at(y)->display(),str);
#define OUT_OF_RANGE_POS_DISP(x,y,str) QVERIFY_EXCEPTION_THROWN(echiquier.positions.at(x).at(y),std::out_of_range);

void Testing::disp_pos()
{
    QCOMPARE_POS_DISP(0, 0, "a1");
    QCOMPARE_POS_DISP(2, 4, "c5");
    QCOMPARE_POS_DISP(3, 0, "d1");
    QCOMPARE_POS_DISP(7, 7, "h8");
    QCOMPARE_POS_DISP(5, 6, "f7");
    OUT_OF_RANGE_POS_DISP(9, 3, "a1");
    OUT_OF_RANGE_POS_DISP(1, 13, "c8");
}

#define CHECK_TOUR_MOVE_OK(c,l) {Tour t(WHITE); t.position = pos_t; Position new_pos(c,l); QCOMPARE(t.move(new_pos),0); QVERIFY(!new_pos.isFree); QVERIFY()}
#define CHECK_TOUR_MOVE_EXC(c,l) {Tour t(WHITE); t.position = pos_t; Position new_pos(c,l); QVERIFY_EXCEPTION_THROWN(t.move(new_pos),ChessException);}

void Testing::move_tour()
{
    echiquier.getPosition("b3")->display();//piece = new Tour(WHITE, echiquier.getPosition("b3"));
  //  echiquier.getPosition("b3")->piece->move(a,3);
//    pos_b.isFree = false;
//    CHECK_TOUR_MOVE_OK(e,1);
//    CHECK_TOUR_MOVE_OK(e,3);
//    CHECK_TOUR_MOVE_OK(a,2);
//    CHECK_TOUR_MOVE_OK(f,2);

//    CHECK_TOUR_MOVE_EXC(10,3);
//    CHECK_TOUR_MOVE_EXC(a,1);
//    CHECK_TOUR_MOVE_EXC(g,1);
//    CHECK_TOUR_MOVE_EXC(e,6);
}
QTEST_APPLESS_MAIN(Testing)

#include "tst_testing.moc"
