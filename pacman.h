#ifndef PACMAN_H
#define PACMAN_H
#include "role.h"
#include <QKeyEvent>
#include <QDebug>
#include <QFile>
#include <QString>
#include <QObject>
class Pacman: public Role {
    Q_OBJECT
public:
    Pacman();
    void keyPressEvent(QKeyEvent *event);
    void canmove(int i);
    void pause();
    virtual void check();
    virtual void play();
    virtual void stop();
public slots:
    virtual void change();
    virtual void move();
private:
    int tmp;
    int direction;
    int movable;
    int row, col;
    int i;
    bool start;
    QPixmap shape[4][4];
    QTimer *timer;
};

#endif // PACMAN_H
