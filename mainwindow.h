#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QKeyEvent>
#include <QDebug>
#include <QFile>
#include <QPushButton>
#include <QTimer>
#include <QProcess>
#include "role.h"
#include "pacman.h"
#include "blinky.h"
#include "clyde.h"
#include "inky.h"
#include "pinky.h"
#include "item.h"
#include "dot.h"
#include "pellet.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    void stop();
    ~MainWindow();
public slots:
    void check();
    void play();
    void pacinfo();
    void mode();
    void quit();
    void stopgame();
    void recover();
private:
    Ui::MainWindow *ui;

    QGraphicsScene *scene;
    QGraphicsTextItem *score, *win, *lose;
    QGraphicsPixmapItem *mapimg, *title;
    QPushButton *start, *newgame, *pause;
    QString map[31][28];
    Role *ptr, *ptr1, *ptr2, *ptr3, *ptr4;
    Item *item[31][28];
    QTimer *count, *pos, *frighten, *stopGame;
    int point;
    int dotnum;
    bool scared;
    bool scared1, scared2, scared3, scared4;
};

#endif // MAINWINDOW_H
