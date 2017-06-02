#include"Minionred.h"
#include<QPixmap>
#include<QObject>
#include<QTimer>
#include<QGraphicsScene>
#include<QVector>
#include<QPointF>
#include<QPolygonF>
#include<QLineF>
#include "Game.h"

extern Game * game;

Minionred::Minionred(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent){

    //define team
     team = 1;

   //draw pic
    setPixmap(QPixmap(":images/minionred.jpg"));

   //set  timer
    QTimer * move_timer = new QTimer(this);
    connect(move_timer,SIGNAL(timeout()),this,SLOT(move()));
    move_timer->start(100);

   //create a polygon

   QVector<QPointF> points;
   points << QPoint(1,0) << QPoint(2,0) << QPoint(3,1) << QPoint(3,2) << QPoint(2,3)
         << QPoint(1,3) << QPoint(0,2) << QPoint(0,1);
   //scale polygon
   int i,n;
   int scale = 60;
   for(i=0,n=points.size();i<n;i++){
       points[i]=points[i]*scale;
   }

   //create polygonitem
   attack_area = new QGraphicsPolygonItem(QPolygonF(points),this);

   //match polygon and minion
   QPointF poly_center(1.5,1.5);
   poly_center = poly_center * scale;
   poly_center = mapToScene(poly_center);
   QPointF Minion_center(x()+28,y()+40);
   QLineF ln(poly_center,Minion_center);
   attack_area->setPos(x()+ln.dx(),y()+ln.dy());
}

void Minionred::move(){

     setPos(x()+10,y());
     if (pos().x()>1300){
             scene()->removeItem(this);
             delete this;

         }

    }
