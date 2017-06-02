#include <QPixmap>
#include <QTimer>
#include <qmath.h> // qSin, qCos, qTan
#include "Game.h"
#include <QLine>
#include <QList>
#include "enemyMinion.h"

extern Game * game;

Bullet::Bullet(QGraphicsItem *parent): QObject(),QGraphicsPixmapItem(parent){
    // set graphics
    setPixmap(QPixmap(":images/bullet.jpg"));


    // connect a timer to move()

    connect(move_timer,SIGNAL(timeout()),this,SLOT(move()));
    move_timer->start(50);

}

Bullet::~Bullet()
{
    move_timer->stop();
    delete move_timer;

}








void Bullet::move(){
    double slope = 10;
    double theta = rotation();
    double dy = slope * qSin(qDegreesToRadians(theta));
      double dx = slope * qCos(qDegreesToRadians(theta));
      this ->setPos(x()+dx,y()+dy);

      //delete after collide with enemy
      QList <QGraphicsItem*>coenemy = this -> collidingItems();
      int a = coenemy.size();
      for(int i = 0;i<a;i++){
          if(typeid(*(coenemy[i])) == typeid(enemyMinion)||typeid(*(coenemy[i])) == typeid(Minion)){
              scene() -> removeItem(this);
              delete this;

          }
      }

}
