#ifndef BOARD_H
#define BOARD_H

#include <QWidget>
#include <QPushButton>
#include <QGridLayout>
#include <QSignalMapper>

class Board : public QWidget
{
    Q_OBJECT
public:
    explicit Board(QWidget *parent = nullptr);

signals:

public slots:

public:
    QGridLayout *grid_layout;
};

#endif // BOARD_H
