/*************************************************************************************
** QAPMaker: An interactive tool for developing simple Quadratic Arithmetic Programs
**
** Built using Qt 5.6
**
** Tom Trevethan 2017
** tptrevethan@googlemail.com
**************************************************************************************/

#ifndef CIRCUITSCENE
#define CIRCUITSCENE

#include <QGraphicsScene>

QT_BEGIN_NAMESPACE
class QGraphicsSceneMouseEvent;
class QMenu;
class QPointF;
class QGraphicsLineItem;
class QFont;
class QGraphicsTextItem;
class QGraphicsItem;
class QColor;

QT_END_NAMESPACE

class CircuitScene : public QGraphicsScene
{
    Q_OBJECT

public:
    enum Mode { InsertUSite, InsertSite, InsertTrans, MoveItem };

    explicit CircuitScene(QMenu *gateMenu, QMenu *wireMenu,int xc, int yc, QObject *parent = 0);

public slots:
//    void setMode(Mode mode);

signals:
    void itemSelected(QGraphicsItem *item);
    void itemdeSelected(QGraphicsItem *item);

protected:
//    void mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent) Q_DECL_OVERRIDE;
//    void mouseMoveEvent(QGraphicsSceneMouseEvent *mouseEvent) Q_DECL_OVERRIDE;
//    void mouseReleaseEvent(QGraphicsSceneMouseEvent *mouseEvent) Q_DECL_OVERRIDE;

private:
    bool isItemChange(int type);

    QMenu *myGateMenu;
    QMenu *myWireMenu;
    Mode myMode;
    bool leftButtonDown;
    QPointF startPoint;
    QGraphicsLineItem *line;
    QColor myItemColor;
    QColor myLineColor;
    int xcell; // cell x dimension
    int ycell; // cell y dimension
    int gridSize;
    bool snap;
};

#endif // CIRCUITSCENE

