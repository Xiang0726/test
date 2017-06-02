#ifndef BULLET_H
#define BULLET_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include "enemyMinion.h"
#include<QTimer>
class Bullet: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Bullet(QGraphicsItem * parent=0);
    QTimer * move_timer = new QTimer(this);
    ~Bullet();


public slots:
    void move();
};
#endif // BULLET_H
