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

    explicit ConfigScene(QMenu *gateMenu, QMenu *wireMenu,int xc, int yc, QObject *parent = 0);

    void addSite(bool ostate, double en, double xc, double yc, int sindx, int xrep, int yrep,
             double m1, double m2, double m3, double m4, double m5, double m6);
    void addTrans(Site *myStartItem, Site *myEndItem, double nbar, int id, double startPF, double endPF);
    void addTransPair(Site *myStartItem1, Site *myEndItem1,Site *myStartItem2, Site *myEndItem2, double nbar);

    int getGridSize() const { return this->gridSize; }
    bool getSnap() { return this->snap; }
    void setSnap(bool dosnap) { snap = dosnap; }
    void changeCell(int xcelln, int ycelln) { xcell = xcelln; ycell = ycelln; }

//    void setTransMin1(double energy);
//    void setTransMin2(double energy);
//    void setTransBar(double energy);
//    void setStartMod(int nn, double energy);
//    void setEndMod(int nn, double energy);
//    void setStartPreFac(double pf);
//    void setEndPreFac(double pf);

public slots:
    void setMode(Mode mode);

signals:
    void itemSelected(QGraphicsItem *item);
    void itemdeSelected(QGraphicsItem *item);

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent) Q_DECL_OVERRIDE;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *mouseEvent) Q_DECL_OVERRIDE;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *mouseEvent) Q_DECL_OVERRIDE;

private:
    bool isItemChange(int type);

    QMenu *mySiteMenu;
    QMenu *myTransMenu;
    Mode myMode;
    bool leftButtonDown;
    QPointF startPoint;
    QGraphicsLineItem *line;
    QColor myItemColor;
    QColor myLineColor;
    int xcell; // cell x dimension
    int ycell; // cell y dimension
    int indx; // index for linking periodic transitions
    int gridSize;
    bool snap;
};

#endif // CIRCUITSCENE

