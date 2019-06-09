#ifndef INKY_H
#define INKY_H
#include "role.h"
#include <QDebug>

class Inky: public Role {
public:
    Inky();
    virtual void play();
    virtual void stop();
    virtual void check();
    void changemode(int i);
    void setpac(int x, int y);
    void init();
    QPixmap inky[4][2];
    QPixmap frightened[1][2];
    int tmp;
    int direction;
    int movable;
    int row, col;
    int i;
    int mode;
    bool start;
    int pacx, pacy;

public slots:
    virtual void change();
    virtual void move();
};
#endif // INKY_H
