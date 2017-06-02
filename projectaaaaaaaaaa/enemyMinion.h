#ifndef ENEMYMINION_H
#define ENEMYMINION_H
#include<QGraphicsPixmapItem>
#include<QGraphicsPolygonItem>
#include<QGraphicsItem>
#include"Bullet.h"
#include<QTimer>
class enemyMinion : public QObject,public QGraphicsPixmapItem{
    Q_OBJECT


public:
    enemyMinion(QGraphicsItem * parent=0);
    QGraphicsPolygonItem *attack_area;
    int team;
    int hp;
    void hpdecreace();
    void attack();
    QPointF target;
    bool has;
    ~enemyMinion();
    QTimer * move_timer = new QTimer(this);
public slots:
    void move();

};
#endif // ENEMYMINION_H
