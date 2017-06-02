#include"Tower.h"
#include<QPixmap>
#include<QVector>
#include<QPointF>
#include<QPolygonF>
#include"Bullet.h"
#include"Game.h"
#include<QTimer>
#include<QLineF>
#include <QGraphicsRectItem>
#include"Minionred.h"

extern Game * game;
Tower::Tower(QGraphicsItem *parent): QObject(),  QGraphicsPixmapItem(parent){
    // set graphics
    setPixmap(QPixmap(":/images/tower.png"));

    // craet points vector
    QVector<QPointF> points;
    points << QPointF (1,0) << QPointF (2,0) << QPointF (3,1) << QPointF (3,2) << QPointF (2,3)
           << QPointF (1,3) << QPointF (0,2) << QPointF (0,1);

    //scale
      int scale = 50;
      for(size_t a=0,n=points.size();a<n;a++){
          points[a] = points[a] * scale;
      }

    // create a polygon
    QPolygonF polygon(points);

    // creat the QGraphicPolygonItem
    attack_area = new QGraphicsPolygonItem (polygon,this);

    // move the polygon
    QPointF polygon_center(1.5,1.5);
    polygon_center = polygon_center * scale;
    polygon_center = mapToScene(polygon_center);
    QPointF tower_center (x()+30,y()+55);
    QLineF line(polygon_center,tower_center);
    attack_area->setPos(x()+line.dx(),y()+line.dy());

    // connect a timer to attack_target
    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(acquire_target()));
    timer->start(200);

    // set attack_dest
    attack_dest= QPointF (500,0);


}

double Tower::distance_to(QGraphicsItem *item){
    QLineF line(pos(),item->pos());
    return line.length();

}

void Tower::attack_target(){
   Bullet * bullet = new Bullet();

   bullet->setPos(x(),y());
   QLineF ln(QPointF(x()+30,y()+35),attack_dest);
   int angle = -1 * ln.angle();

   bullet->setRotation(angle);
   game->scene->addItem(bullet);

}

void Tower::acquire_target(){
 // get a list of all items colliding with attack_area
    QList<QGraphicsItem *> colliding_items = attack_area->collidingItems();

    if(colliding_items.size() == 1){
        target_exist = false;
        return;
}
    double closest_dist = 300;
    QPointF closest_point = QPointF (0,0);

    for(size_t a =0,n=colliding_items.size(); a<n; a++){

        Minionred * minion = dynamic_cast<Minionred *>(colliding_items[a]);

        if(minion){
            double this_list =distance_to(minion);
            if(this_list < closest_dist){
                closest_dist = this_list;
                closest_point = colliding_items[a]->pos();
                target_exist = true;
            }

        }
   }
  attack_dest = closest_point ;
  attack_target();
}
