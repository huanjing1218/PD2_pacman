#ifndef CLYDE_H
#define CLYDE_H
#include "role.h"
#include <QDebug>

class Clyde: public Role {
public:
    Clyde();
    virtual void play();
    virtual void stop();
    virtual void check();
    void changemode(int i);
    void setpac(int x, int y);
    void init();
    QPixmap clyde[4][2];
    QPixmap frightened[1][2];
    int tmp;
    int direction;
    int movable;
    int row, col;
    int i;
    int mode;
    bool start;
    bool scared;
    int pacx, pacy;

public slots:
    virtual void change();
    virtual void move();
};
#endif // CLYDE_H
