#ifndef MINIONRED_H
#define MINIONRED_H

#include<QGraphicsPixmapItem>
#include<QGraphicsPolygonItem>
#include<QGraphicsItem>
class Minionred : public QObject,public QGraphicsPixmapItem{
    Q_OBJECT


public:
    Minionred(QGraphicsItem * parent=0);
    QGraphicsPolygonItem *attack_area;
    int team;
public slots:
    void move();
};
#endif // MINIONRED_H
