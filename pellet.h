#ifndef PELLET_H
#define PELLET_H
#include <QObject>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include "item.h"

class Pellet: public Item {
    Q_OBJECT
public:
    Pellet();
    QTimer *timer;
public slots:
    void change();
private:
    int i;
};

#endif // PELLET_H
