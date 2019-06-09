#include "blinky.h"

Blinky::Blinky() {
    blinky[0][0].load(":/img/blinkyu1.png");
    blinky[0][1].load(":/img/blinkyu2.png");
    blinky[1][0].load(":/img/blinkyd1.png");
    blinky[1][1].load(":/img/blinkyd2.png");
    blinky[2][0].load(":/img/blinkyl1.png");
    blinky[2][1].load(":/img/blinkyl2.png");
    blinky[3][0].load(":/img/blinkyr1.png");
    blinky[3][1].load(":/img/blinkyr2.png");
    frightened[0][0].load(":/img/nerf11.png");
    frightened[0][1].load(":/img/nerf12.png");
    this->setPixmap(blinky[3][0].scaled(35,35));
    row = 11;
    col = 13;
    this->setPos(20*col-5, 20*row-5);
    direction = 4;
    i = 0;
    mode = 0;
    movable = 0;
    start = false;
    scared = false;
}

void Blinky::move() {
    if(start) {
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
        //qDebug() << movable;
    }
}

void Blinky::check() {
    row = int(this->y()+5) / 20;
    col = int(this->x()+5) / 20;
    //qDebug() << row << "" << col;
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
    //qDebug() << "\n\n";
    //qDebug() << movable;
}

void Blinky::play() {
    start = true;
}

void Blinky::stop() {
    start = false;
}

void Blinky::change() {
    if(start) {
        if(mode == 0)
            setPixmap(blinky[movable-1][i].scaled(35,35));
        else if(mode == 1)
            setPixmap(frightened[0][i].scaled(35,35));
        if(i == 0)
            i =1;
        else {
            i = 0;
        }
    }
}

void Blinky::setpac(int x, int y) {
    pacx = x;
    pacy = y;
}

void Blinky::changemode(int i) {
    mode = i;
    if(i == 0)
        scared = false;
    else {
        scared = true;
    }
}

void Blinky::init() {
    row = 11;
    col = 13;
    this->setPos(20*col-5, 20*row-5);
    mode = 0;
}
