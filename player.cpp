#include "player.h"
#include <QGraphicsScene>
#include <QDebug>

Player::Player() : velocityY(0), isJumping(false)
{
    setPixmap(QPixmap(":/images/player.png"));
}

void Player::move()
{
    if (isJumping) {
        velocityY += 0.5; // 重力
        setPos(x(), y() + velocityY);

        if (y() >= 500) {
            setPos(x(), 500);
            isJumping = false;
            velocityY = 0;
        }
    }
}

void Player::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Space && !isJumping) {
        isJumping = true;
        velocityY = -15; // 跳跃初速度
    }
}
