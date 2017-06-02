#ifndef TOWER_H
#define TOWER_H
#include<QGraphicsPixmapItem>
#include<QGraphicsPolygonItem>
#include<QGraphicsItem>
#include<QPointF>
#include<QObject>

class Tower : public QObject, public QGraphicsPixmapItem{
    Q_OBJECT

public:
    Tower (QGraphicsItem * parent=0);

    QGraphicsPolygonItem * attack_area;

    QPointF attack_dest;

    double distance_to(QGraphicsItem * item);

    void attack_target();
    bool target_exist ;
public slots:

    void acquire_target();


};


#endif // TOWER_H
