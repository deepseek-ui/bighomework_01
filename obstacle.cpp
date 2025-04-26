#include "obstacle.h"
#include <QGraphicsScene>

Obstacle::Obstacle(QGraphicsItem *parent) :
    QObject(nullptr),               // 初始化QObject
    QGraphicsPixmapItem(parent)     // 初始化图形项
{
    setPixmap(QPixmap(":/images/obstacle.png"));

    timer = new QTimer(this);       // 现在可以正确传递this（因为继承了QObject）
    connect(timer, &QTimer::timeout, this, &Obstacle::move);
    timer->start(16);
}

void Obstacle::move()
{
    setPos(x() - 5, y());

    if (x() + pixmap().width() < 0) {
        scene()->removeItem(this);
        delete this;
    }
}
