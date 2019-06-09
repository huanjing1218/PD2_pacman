#include "pellet.h"

Pellet::Pellet() {
    item.load(":/img/pellet.png");
    this->setPixmap(item.scaled(20,20));

    i = 0;
    timer = new QTimer();
    timer->start(200);
    connect(timer, SIGNAL(timeout()), this, SLOT(change()));
}

void Pellet::change() {
    if(i == 0) {
        this->hide();
        i = 1;
    }
    else {
        this->show();
        i = 0;
    }
}
