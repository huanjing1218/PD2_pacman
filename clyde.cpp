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
    this->setPixmap(clyde[1][0].scaled(35,35));
    row = 13;
    col = 9;
    this->setPos(20*col-5, 20*row-5);
    //direction = 2;
    i = 0;
    mode = 0;
    movable = 4;
    start = false;
    scared = false;
}

void Clyde::move() {
    if(start) {
        //qDebug() << pos();
        if(int(this->x()+5) % 20 == 0 && int(this->y()+5) % 20 == 0)
            check();
        if(movable == 1)
            setY(int(this->y() - 1));
        else if(movable == 2)
            setY(int(this->y() + 1));
        else if(movable == 3)
            setX(int(this->x() - 1));
        else if(movable == 4)
            setX(int(this->x() + 1));
    }
}

void Clyde::check() {
    row = int(this->y()+5) / 20;
    col = int(this->x()+5) / 20;
    //qDebug() << this->pos();
    int min = 0;
    tmp = movable;
    movable = 0;
    if(map[row-1][col] != "0") {
        if(tmp != 2) {
            movable = 1;
            min = (int(this->x())-pacx) + abs(int(this->y())-20-pacy);
        }
        //qDebug() << (int(this->x())-pacx) + abs(int(this->y())-20-pacy);
    }
    if(map[row+1][col] != "0") {
        //qDebug() << abs(int(this->x())-pacx) + abs(int(this->y()+20-pacy));
        if(min == 0) {
            movable = 2;
            min = (abs(int(this->x())-pacx) + abs(int(this->y()+20-pacy)));
            //qDebug() << abs(int(this->x())-pacx) + abs(int(this->y()+20-pacy));
        }
        else if((abs(int(this->x())-pacx) + abs(int(this->y()+20-pacy))) < min && tmp != 1) {
            movable = 2;
            min = (abs(int(this->x())-pacx) + abs(int(this->y()+20-pacy)));
        }
    }
    if(map[row][col-1] != "0") {
        //qDebug() << abs(int(this->x())-20-pacx) + abs(int(this->y())-pacy);
        if(min == 0) {
            movable = 3;
            min = (abs(int(this->x())-20-pacx) + abs(int(this->y())-pacy));
            //qDebug() << abs(int(this->x())-20-pacx) + abs(int(this->y())-pacy);
        }
        else if((abs(int(this->x())-20-pacx) + abs(int(this->y())-pacy)) < min && tmp != 4) {
            movable = 3;
            min = (abs(int(this->x())-20-pacx) + abs(int(this->y())-pacy));
        }
    }
    if(map[row][col+1] != "0") {
        //qDebug() << abs(int(this->x())+20-pacx) + abs(int(this->y())-pacy);
        if(min == 0) {
            movable = 4;
            min = (abs(int(this->x())+20-pacx) + abs(int(this->y())-pacy));
            //qDebug() << abs(int(this->x())+20-pacx) + abs(int(this->y())-pacy);
        }
        else if((abs(int(this->x())+20-pacx) + abs(int(this->y())-pacy)) < min && tmp != 3) {
            movable = 4;
            min = (abs(int(this->x())+20-pacx) + abs(int(this->y())-pacy));
        }
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
            setPixmap(clyde[movable-1][i].scaled(35,35));
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
    if(i == 0)
        scared = false;
    else
        scared = true;
}

void Clyde::init() {
    row = 13;
    col = 9;
    this->setPos(20*col-5, 20*row-5);
    mode = 0;
}
