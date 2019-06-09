#ifndef DOT_H
#define DOT_H
#include <QObject>
#include <QGraphicsPixmapItem>
#include <QDebug>
#include "item.h"

class Dot: public Item {
    Q_OBJECT
public:
    Dot();
    int num;
};

#endif // DOT_H
