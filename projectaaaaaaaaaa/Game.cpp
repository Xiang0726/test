#include"Game.h"
#include"Minion.h"
#include"Minionred.h"
#include <QGraphicsScene>
#include <QLabel>
#include <enemyMinion.h>
#include <Bullet.h>
#include"Tower.h"
Game::Game(){


  //create scene
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,800,600);
    setScene(scene);

    //CREATE tower
    Tower * t = new Tower();
    t->setPos(0,50);

    // add tower to scene
    scene->addItem(t);
   }
  //chose minion type

void Game::keyPressEvent(QKeyEvent *eventnumber){
    if(eventnumber->key() == Qt::Key_1){
        id = 1;
    }
    else if(eventnumber ->key() == Qt::Key_2){
        id = 2;
    }
    else if(eventnumber ->key() == Qt::Key_3){
        id = 3;
    }
}



void Game::mousePressEvent(QMouseEvent *event){
    if(id == 1){
    //create a greenminion
    Minion * minion = new Minion();
    minion->setPos(event->x()-250,event->y());
    scene->addItem(minion);
    }
    else if(id == 2){
     //create a redminion
    Minionred * minion = new Minionred();
    minion->setPos(event->x()-250,event->y());
    scene->addItem(minion);
    }
    if(id == 3){
    //create a enemyminion
    enemyMinion * minion = new enemyMinion();
    minion->setPos(event->x()-250,event->y());
    scene->addItem(minion);
    }
}




