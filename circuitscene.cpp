/*************************************************************************************
** QAPMaker: An interactive tool for developing simple Quadratic Arithmetic Programs
**
** Built using Qt 5.6
**
** Tom Trevethan 2017
** tptrevethan@googlemail.com
**************************************************************************************/

#include "circuitscene.h"

#include <QTextCursor>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsItemGroup>
#include <QDebug>


CircuitScene::CircuitScene(QMenu *gateMenu, QMenu *wireMenu, int xc, int yc, QObject *parent)
    : QGraphicsScene(parent), gridSize(20)
{
    mySiteMenu = siteMenu;
    myTransMenu = transMenu;
    myMode = InsertUSite;
    line = 0;
    myItemColor = Qt::white;
    myLineColor = Qt::black;
    xcell = xc;
    ycell = yc;
    indx = 1;
    snap = false;
}

