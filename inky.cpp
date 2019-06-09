#include "inky.h"

Inky::Inky() {
    inky[0][0].load(":/img/inkyu1.png");
    inky[0][1].load(":/img/inkyu2.png");
    inky[1][0].load(":/img/inkyd1.png");
    inky[1][1].load(":/img/inkyd2.png");
    inky[2][0].load(":/img/inkyl1.png");
    inky[2][1].load(":/img/inkyl2.png");
    inky[3][0].load(":/img/inkyr1.png");
    inky[3][1].load(":/img/inkyr2.png");
    frightened[0][0].load(":/img/nerf11.png");
    frightened[0][1].load(":/img/nerf12.png");
    this->setPixmap(inky[3][0].scaled(35,35));
    row = 29;
    col = 1;
    this->setPos(20*col-5, 20*row-5);
    direction = 1;
    i = 0;
    mode = 0;
    movable = 1;
    start = false;
}

void Inky::move() {
    if(start) {

    }
}

void Inky::check() {

}

void Inky::play() {
    start = true;
}

void Inky::stop() {
    start = false;
}

void Inky::change() {
    if(start) {
        if(mode == 0)
            setPixmap(inky[direction-1][i].scaled(35,35));
        else if(mode == 1)
            setPixmap(frightened[0][i].scaled(35,35));
        if(i == 0)
            i = 1;
        else
            i = 0;
    }
}

void Inky::setpac(int x, int y) {
    pacx = x;
    pacy = y;
}

void Inky::changemode(int i) {
    mode = i;
}

void Inky::init() {
    row = 29;
    col = 1;
    this->setPos(20*col-5, 20*row-5);
    mode = 0;
}
