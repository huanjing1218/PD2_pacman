#include "role.h"

Role::Role() {
    timer1 = new QTimer();
    timer1->start(10);
    connect(timer1, SIGNAL(timeout()), this, SLOT(move()));

    timer2 = new QTimer();
    timer2->start(100);
    connect(timer2, SIGNAL(timeout()), this, SLOT(change()));

    QString data;
    QFile file(":/map/map.txt");
    file.open(QIODevice::ReadOnly);
    while(!file.atEnd()) {
        for(int i = 0; i < 31; ++i) {
            data = file.readLine();
            for(int j = 0; j < 28; ++j) {
                map[i][j] = data[j];
            }
        }
    }
}

void Role::setpac(int x, int y) {

}

void Role::changemode(int i) {

}

void Role::init() {

}
