#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsPixmapItem>
#include <QKeyEvent>

class Player : public QGraphicsPixmapItem
{
public:
    Player();
    void move();

protected:
    void keyPressEvent(QKeyEvent *event) override;

private:
    qreal velocityY;
    bool isJumping;
};

#endif // PLAYER_H
