#ifndef ROLE_H
#define ROLE_H
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QTimer>
#include <QDebug>
#include <QFile>

class Role: public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
public:
    Role();
    virtual void check() = 0;
    virtual void play() = 0;
    virtual void stop() = 0;
    virtual void setpac(int x, int y);
    virtual void changemode(int i);
    virtual void init();
    virtual void pause();
    QTimer *timer1, *timer2;
    QString map[31][28];
public slots:
    virtual void move() = 0;
    virtual void change() = 0;
};

#endif // ROLE_H
