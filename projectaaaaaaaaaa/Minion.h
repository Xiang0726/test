#ifndef MINION_H
#define MINION_H

#include<QGraphicsPixmapItem>
#include<QGraphicsPolygonItem>
#include<QGraphicsItem>
#include<QTimer>
class Minion : public QObject,public QGraphicsPixmapItem{
    Q_OBJECT


public:
    Minion(QGraphicsItem * parent=0);
    ~Minion();
    QGraphicsPolygonItem *attack_area;
    bool has;
    int team;
    void attack();
    QPointF target;
    int hp;
    QTimer * move_timer = new QTimer(this);

public slots:
    void move();




};

#endif // MINION_H
