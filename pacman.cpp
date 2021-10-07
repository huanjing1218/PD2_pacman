#include "pacman.h"

Pacman::Pacman() {

    shape[0][0].load(":/img/pacmanu1.png");
    shape[0][1].load(":/img/pacmanu2.png");
    shape[0][2].load(":/img/pacmanud.png");
    shape[0][3].load(":/img/pacmanu2.png");//up
    shape[1][0].load(":/img/pacmand1.png");
    shape[1][1].load(":/img/pacmand2.png");
    shape[1][2].load(":/img/pacmanud.png");
    shape[1][3].load(":/img/pacmand2.png");//down
    shape[2][0].load(":/img/pacmanl1.png");
    shape[2][1].load(":/img/pacmanl2.png");
    shape[2][2].load(":/img/pacmanlr.png");
    shape[2][3].load(":/img/pacmanl2.png");//left
    shape[3][0].load(":/img/pacmanr1.png");
    shape[3][1].load(":/img/pacmanr2.png");
    shape[3][2].load(":/img/pacmanlr.png");
    shape[3][3].load(":/img/pacmanr2.png");//right
    this->setPixmap(shape[3][0].scaled(35,35));

    start = false;
    direction = 0;
    tmp = 4;//
    row = 23;
    col = 13;
    this->setPos(20*col-5, 20*row-5);
    movable = 4;//
    i = 0;

}

void Pacman::keyPressEvent(QKeyEvent *event) {
    if(start) {
        if(event->key() == Qt::Key_Up) {
            if(direction != 1) {
                tmp = direction;
                direction = 1;
            }
        }
        else if(event->key() == Qt::Key_Down) {
            if(direction != 2) {
                tmp = direction;
                direction = 2;
            }
        }
        else if(event->key() == Qt::Key_Left) {
            if(direction != 3) {
                tmp = direction;
                direction = 3;
            }
        }
        else if(event->key() == Qt::Key_Right) {
            if(direction != 4) {
                tmp = direction;
                direction = 4;
            }
        }
    }
}

void Pacman::move() {
if(start) {
    if(int(this->x()+5) % 20 == 0 && int(this->y()+5) % 20 == 0) {
        row = int(this->y()+5) / 20;
        col = int(this->x()+5) / 20;
        check();        

        if(movable == 0)
           return;
        if(movable == 3 && int(this->x()) == 15 && int(this->y()) == 275) {
            this->setPos(535,275);
            return;
        }
        if(movable == 4 && int(this->x()) == 535 && int(this->y()) == 275) {
            this->setPos(-5,275);
            return;
        }
    }


    if(movable != 0) {
        tmp = movable;
        if(movable == 1) {
            setY(int(this->y() - 1));
        }
        else if(movable == 2) {
            setY(int(this->y() + 1));
        }
        else if(movable == 3) {
            setX(int(this->x() - 1));
        }
        else if(movable == 4) {
            setX(int(this->x() + 1));
        }
    }
    qDebug() << movable;
    //qDebug() << this->pos();
}
}

void Pacman::check() {
    //qDebug() << direction << "" << tmp;

    movable = direction;
    canmove(direction);
    //qDebug() << movable;

    if(movable != 0)
        return;

    movable = tmp;
    canmove(tmp);
    //qDebug() << movable << "\n";
 }

void Pacman::canmove(int i) {
    if(i == 1) {
        if(row - 1 >= 0) {
            if(map[row-1][col] == "0") {
                movable = 0;
            }
        }
    }
    else if(i == 2) {
        if(row + 1 <= 31) {
            if(map[row+1][col] == "0") {
                movable = 0;
            }
        }
    }
    else if(i == 3) {
        if(col - 1 >= 0) {
            if(map[row][col-1] == "0") {
                movable = 0;
            }
         }
    }
    else if(i == 4) {
        if(col + 1 < 28) {
            if(map[row][col+1] == "0") {
                movable = 0;
            }
        }
    }
}

void Pacman::change() {
    //qDebug() << i;
if(start) {
    if(movable == 0)
        return;
    setPixmap(shape[movable-1][i].scaled(35,35));
    i++;
    if(i == 4)
        i = 0;
}
}
void Pacman::play() {
    //movable = 4;
    //tmp = 4;
    start = true;
}

void Pacman::stop() {
    //movable = 0;
    //tmp = 0;
    //direction = 0;
    start = false;
}

void Pacman::pause() {
    if(start)
        start = false;
    else
        start = true;
}
