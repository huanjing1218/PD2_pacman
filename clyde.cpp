#include "clyde.h"

Clyde::Clyde() {
    clyde[0][0].load(":/img/clydeu1.png");
    clyde[0][1].load(":/img/clydeu2.png");
    clyde[1][0].load(":/img/clyded1.png");
    clyde[1][1].load(":/img/clyded2.png");
    clyde[2][0].load(":/img/clydel1.png");
    clyde[2][1].load(":/img/clydel2.png");
    clyde[3][0].load(":/img/clyder1.png");
    clyde[3][1].load(":/img/clyder2.png");
    frightened[0][0].load(":/img/nerf11.png");
    frightened[0][1].load(":/img/nerf12.png");
    this->setPixmap(clyde[3][0].scaled(35,35));
    row = 1;
    col = 26;
    this->setPos(20*col-5, 20*row-5);
    direction = 3;
    i = 0;
    mode = 0;
    movable = 3;
    record = 0;
    start = false;
}

void Clyde::move() {
    if(start) {
        /*if(int(this->x()+5) % 20 == 0 && int(this->y()+5) % 20)
            check();
        if(movable == 1)
            setY(int(this->y() - 1));
        else if(movable == 2)
            setY(int(this->y() + 1));
        else if(movable == 3)
            setX(int(this->x() - 1));
        else if(movable == 4)
            setX(int(this->x() + 1));
    */}
}

void Clyde::check() {
    //movable = route[record];
    row = int(this->y()+5) / 20;
    col = int(this->x()+5) / 20;
    //qDebug() << route[record];
    if(row == 1) {
        if(col == 26)
            movable = 3;
        else if(col == 21)
            movable = 2;
    }
    if(row == 5) {
        if(col == 21)
            movable = 3;
        else if(col == 18)
            movable = 2;
    }
    if(row == 8) {
        if(col == 18)
            movable = 3;
        else if(col == 15)
            movable =2;
    }
    if(row == 11) {
        if(col == 15)
            movable = 4;
        else if(col == 18)
            movable = 2;
    }
    if(row == 14) {
        if(col == 18)
            movable = 4;
        else if(col == 21)
            movable = 1;
    }



}

void Clyde::play() {
    start = true;
}

void Clyde::stop() {
    start = false;
}

void Clyde::change() {
    if(start) {
        if(mode == 0)
            setPixmap(clyde[movable-i][i].scaled(35,35));
        else if(mode == 1)
            setPixmap(frightened[0][i].scaled(35,35));
        if(i == 0)
            i = 1;
        else
            i = 0;
    }
}

void Clyde::setpac(int x, int y) {
    pacx = x;
    pacy = y;
}

void Clyde::changemode(int i) {
    mode = i;
}

void Clyde::init() {
    row = 1;
    col = 26;
    this->setPos(20*col-5, 20*row-5);
    mode = 0;
}
