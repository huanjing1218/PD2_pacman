#include "pinky.h"

Pinky::Pinky() {
    pinky[0][0].load(":/img/pinkyu1.png");
    pinky[0][1].load(":/img/pinkyu2.png");
    pinky[1][0].load(":/img/pinkyd1.png");
    pinky[1][1].load(":/img/pinkyd2.png");
    pinky[2][0].load(":/img/pinkyl1.png");
    pinky[2][1].load(":/img/pinkyl2.png");
    pinky[3][0].load(":/img/pinkyr1.png");
    pinky[3][1].load(":/img/pinkyr2.png");
    frightened[0][0].load(":/img/nerf11.png");
    frightened[0][1].load(":/img/nerf12.png");
    this->setPixmap(pinky[3][0].scaled(35,35));
    row = 14;
    col = 15;
    this->setPos(20*col-5, 20*row-5);
    direction = 3;
    i = 0;
    mode = 0;
    movable = 3;
    start = false;
}

void Pinky::move() {
    if(start) {

    }
}

void Pinky::check() {

}

void Pinky::play() {
    start = true;
}

void Pinky::stop() {
    start = false;
}

void Pinky::change() {
    if(start) {
        if(mode == 0)
            setPixmap(pinky[direction-1][i].scaled(35,35));
        else if(mode == 1)
            setPixmap(frightened[0][i].scaled(35,35));
        if(i == 0)
            i = 1;
        else
            i = 0;
    }
}

void Pinky::setpac(int x, int y) {
    pacx = x;
    pacy = y;
}

void Pinky::changemode(int i) {
    mode = i;
}

void Pinky::init() {
    row = 14;
    col = 15;
    this->setPos(20*col-5, 20*row-5);
    mode = 0;
}
