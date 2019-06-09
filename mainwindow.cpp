#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->scene = new QGraphicsScene(0,0,ui->graphicsView->width()-2,ui->graphicsView->height()-2);
    ui->graphicsView->setScene(scene);
    mapimg = new QGraphicsPixmapItem(QPixmap(":/img/map.png"));
    scene->addItem(mapimg);

    point = 0;
    dotnum = 0;
    scared = false;

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
    for(int i = 0; i < 31; ++i) {
        for(int j = 0; j < 28; ++j) {
            if(map[i][j] == "1") {
                item[i][j] = new Dot();
                item[i][j]->setPos(20*j, 20*i);
                scene->addItem(item[i][j]);
                dotnum++;
            }
            else if(map[i][j] == "2") {
                item[i][j] = new Pellet();
                item[i][j]->setPos(20*j, 20*i);
                scene->addItem(item[i][j]);
                dotnum++;
            }
            //qDebug() << dotnum;
        }
    }

    ptr1 = new Blinky();
    scene->addItem(ptr1);
    ptr2 = new Clyde();
    scene->addItem(ptr2);
    ptr3 = new Inky();
    scene->addItem(ptr3);
    ptr4 = new Pinky();
    scene->addItem(ptr4);
    ptr = new Pacman();
    scene->addItem(ptr);
    ptr->setFlag(QGraphicsItem::ItemIsFocusable);
    ptr->setFocus();

    count = new QTimer();
    count->start(10);
    connect(count, SIGNAL(timeout()), this, SLOT(check()));

    score = new QGraphicsTextItem();
    score->setDefaultTextColor(Qt::white);
    score->setFont(QFont("Times", 30));
    score->setPos(160,617);
    scene->addItem(score);

    start = new QPushButton("START", this);
    start->setFont(QFont("", 25));
    start->setPalette(QColor(Qt::blue));
    start->setGeometry(180,360,200,60);
    start->setStyleSheet("color:white");
    connect(start, SIGNAL(clicked()), this, SLOT(play()));

    newgame = new QPushButton("NEW GAME", this);
    newgame->setFont(QFont("", 25));
    newgame->setPalette(QColor(Qt::blue));
    newgame->setGeometry(180,360,200,60);
    newgame->setStyleSheet("color:white");
    connect(newgame, SIGNAL(clicked()), this, SLOT(quit()));
    newgame->hide();

    title = new QGraphicsPixmapItem();
    title->setPixmap(QPixmap(":/img/title.png").scaled(420,100));
    title->setPos(70,150);
    scene->addItem(title);

    pos = new QTimer();
    pos->start(10);
    connect(pos, SIGNAL(timeout()), this, SLOT(pacinfo()));

    frighten = new QTimer();
    connect(frighten, SIGNAL(timeout()), this, SLOT(mode()));

    win = new QGraphicsTextItem("You win!");
    win->setFont(QFont("Comic Sans MS", 70));
    win->setDefaultTextColor(QColor(Qt::red));
    win->setPos(115,240);
    scene->addItem(win);
    win->hide();

    lose = new QGraphicsTextItem("Game Over");
    lose->setFont(QFont("Comic Sans MS", 70));
    lose->setDefaultTextColor(QColor(Qt::red));
    lose->setPos(40,240);
    scene->addItem(lose);
    lose->hide();
}

void MainWindow::check() {
    QPoint ptr1pos(int(ptr1->x())+15, int(ptr1->y())+15);
    QPoint ptr2pos(int(ptr2->x())+15, int(ptr2->y())+15);
    QPoint ptr3pos(int(ptr3->x())+15, int(ptr3->y())+15);
    QPoint ptr4pos(int(ptr4->x())+15, int(ptr4->y())+15);
    QPoint ptrpos(int(ptr->x())+15, int(ptr->y())+15);
    if(abs(ptr1pos.x()-ptrpos.x())+abs(ptr1pos.y()-ptrpos.y()) < 30 || abs(ptr2pos.x()-ptrpos.x())+abs(ptr2pos.y()-ptrpos.y()) < 30 || abs(ptr3pos.x()-ptrpos.x())+abs(ptr3pos.y()-ptrpos.y()) < 30 || abs(ptr4pos.x()-ptrpos.x())+abs(ptr4pos.y()-ptrpos.y()) < 30) {
        if(!scared) {
            stop();
            lose->show();
            newgame->show();
        }
        else {
            point += 200;
            if(abs(ptr1pos.x()-ptrpos.x())+abs(ptr1pos.y()-ptrpos.y()) < 30)
                ptr1->init();
            if(abs(ptr2pos.x()-ptrpos.x())+abs(ptr2pos.y()-ptrpos.y()) < 30)
                ptr2->init();
            if(abs(ptr3pos.x()-ptrpos.x())+abs(ptr3pos.y()-ptrpos.y()) < 30)
                ptr3->init();
            if(abs(ptr4pos.x()-ptrpos.x())+abs(ptr4pos.y()-ptrpos.y()) < 30)
                ptr4->init();
        }
    }
    if(int(ptr->x()+5) % 20 == 0 && int(ptr->y()+5) % 20 == 0) {
        int row = int(ptr->y()+5) / 20;
        int col = int(ptr->x()+5) / 20;
        //qDebug() << row << "" << col;
        if(map[row][col]  == "1" || map[row][col] == "2") {
            if(map[row][col] == "1")
                point += 10;
            else if(map[row][col] == "2") {
                point += 50;
                scared = true;
                ptr1->changemode(1);
                ptr2->changemode(1);
                ptr3->changemode(1);
                ptr4->changemode(1);
                frighten->start(10000);
            }
            delete item[row][col];
            map[row][col] = "3";
            dotnum--;
            if(dotnum == 0) {
                stop();
                win->show();
                newgame->show();
            }
        }
        score->setPlainText(QString("%1").arg(QString::number(point)));
        //qDebug() << point;
    }
}

void MainWindow::play() {
    start->hide();
    title->hide();
    ptr->play();
    ptr1->play();
    ptr2->play();
    ptr3->play();
    ptr4->play();
}

void MainWindow::stop() {
    title->show();
    ptr->stop();
    ptr1->stop();
    ptr2->stop();
    ptr3->stop();
    ptr4->stop();
}

void MainWindow::pacinfo() {
    if(int(ptr1->x()+5) % 20 == 0 && int(ptr1->y()+5) % 20 == 0) {
        ptr1->setpac(int(ptr->x()), int(ptr->y()));
        //qDebug() << ptr->pos();
    }
    if(int(ptr2->x()+5) % 20 == 0 && int(ptr2->y()+5) % 20 == 0)
        ptr2->setpac(int(ptr->x()), int(ptr->y()));
    if(int(ptr3->x()+5) % 20 == 0 && int(ptr3->y()+5) % 20 == 0)
        ptr3->setpac(int(ptr->x()), int(ptr->y()));
    if(int(ptr4->x()+5) % 20 == 0 && int(ptr4->y()+5) % 20 == 0)
        ptr4->setpac(int(ptr->x()), int(ptr->y()));
}

void MainWindow::mode() {
   frighten->stop();
   ptr1->changemode(0);
   ptr2->changemode(0);
   ptr3->changemode(0);
   ptr4->changemode(0);
   scared = false;
}

void MainWindow::quit() {
    qApp->quit();
    QProcess::startDetached(qApp->arguments()[0], qApp->arguments());
}

MainWindow::~MainWindow()
{
    delete ui;
}
