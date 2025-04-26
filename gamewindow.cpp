#include "gamewindow.h"
#include <QKeyEvent>
#include <QDebug>

GameWindow::GameWindow(QWidget *parent, bool standalone) : QMainWindow(parent)
{
    scene = new QGraphicsScene(this);
    view = new QGraphicsView(scene, this);
    view->setRenderHint(QPainter::Antialiasing);
    view->setSceneRect(0, 0, 800, 600);

    player = new Player();
    scene->addItem(player);
    player->setPos(100, 500);

    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &GameWindow::update);
    timer->start(16); // 大约60帧每秒

    this->resize(800, 600);
}

GameWindow::~GameWindow()
{
    delete scene;
    delete view;
    delete player;
    delete timer;
}

void GameWindow::update()
{
    player->move();
    spawnObstacle();
}

void GameWindow::spawnObstacle()
{
    static int spawnCounter = 0;
    if (spawnCounter++ % 100 == 0) {
      Obstacle *obstacle = new Obstacle();
        scene->addItem(obstacle);
        obstacle->setPos(800, 500);
    }
}
