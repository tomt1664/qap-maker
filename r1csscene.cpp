/*************************************************************************************
** QAPMaker: An interactive tool for developing simple Quadratic Arithmetic Programs
**
** Built using Qt 5.6
**
** Tom Trevethan 2017
** tptrevethan@googlemail.com
**************************************************************************************/

#include "r1csscene.h"

#include <QTextCursor>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsItemGroup>
#include <QDebug>


R1csScene::R1csScene(QObject *parent)
    : QGraphicsScene(parent)
{
    myItemColor = Qt::white;
    myLineColor = Qt::black;
}
