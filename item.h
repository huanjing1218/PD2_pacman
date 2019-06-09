#ifndef ITEM_H
#define ITEM_H
#include <QObject>
#include <QGraphicsPixmapItem>
#include <QDebug>

class Item: public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
public:
    QPixmap item;

};

#endif // ITEM_H
