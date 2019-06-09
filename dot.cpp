#include "dot.h"

Dot::Dot() {
    item.load(":/img/dot.png");
    this->setPixmap(item.scaled(20,20));
}
