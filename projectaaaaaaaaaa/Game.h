#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QMouseEvent>
#include "Minion.h"
#include <QKeyEvent>
#include "Minionred.h"
#include <enemyMinion.h>
class Game: public QGraphicsView{
public:
    // member functions
    Game();
    void mousePressEvent(QMouseEvent *event);
    void keyPressEvent(QKeyEvent *eventnumber);
    int id;
    // member attributes
    QGraphicsScene * scene;
};

#endif // GAME_H
