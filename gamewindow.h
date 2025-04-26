#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer>
#include "player.h"
#include "obstacle.h"

class GameWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit GameWindow(QWidget *parent = nullptr, bool standalone = true);
    ~GameWindow();

private:
    QGraphicsScene *scene;
    QGraphicsView *view;
    Player *player;
    QTimer *timer;
    void spawnObstacle();

private slots:
    void update();
};

#endif // GAMEWINDOW_H
