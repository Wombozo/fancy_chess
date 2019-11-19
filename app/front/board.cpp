#include "board.h"

Board::Board(QWidget *parent) : QWidget(parent)
{
    grid_layout = new QGridLayout(this);

    for(int i = 0; i < 8; ++i) {
        for(int j = 0; j < 8; ++j) {
            QPushButton* pb = new QPushButton(this);
            pb->setFixedSize(23, 23);
            pb->setLayout(grid_layout);
        }
    }


}
