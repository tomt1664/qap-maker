/*************************************************************************************
** QAPMaker: An interactive tool for developing simple Quadratic Arithmetic Programs
**
** Built using Qt 5.6
**
** Tom Trevethan 2017
** tptrevethan@googlemail.com
**************************************************************************************/

#include "mainwindow.h"
#include "cprog.h"
#include "flatprog.h"
#include "circuitscene.h"
#include "qcustomplot.h"

#include <QtWidgets>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{

    setupMenus();
//    setupWidgets();

    scene = new CircuitScene(gateMenu, wireMenu, 400, 400, this);
    scene->setSceneRect(QRectF(0, 0, 400, 400));
    scene->setBackgroundBrush(Qt::lightGray);

    //connect to configscene for selection/deselection signals
    connect(scene, SIGNAL(itemSelected(QGraphicsItem*)),
                this, SLOT(itemSelected(QGraphicsItem*)));
    connect(scene, SIGNAL(itemdeSelected(QGraphicsItem*)),
                this, SLOT(itemdeSelected(QGraphicsItem*)));


    cell = new QGraphicsRectItem;
    cell->setRect(0, 0, 400, 400);
    cell->setBrush(Qt::white);
    cell->setZValue(-2000);
    scene->addItem(cell);


    zoomSlider = new QSlider;
    zoomSlider->setOrientation(Qt::Horizontal);
    zoomSlider->setMinimum(0);
    zoomSlider->setMaximum(500);
    zoomSlider->setValue(250);



    rotateSlider = new QSlider;
    rotateSlider->setOrientation(Qt::Horizontal);
    rotateSlider->setMinimum(-360);
    rotateSlider->setMaximum(360);
    rotateSlider->setValue(0);




    QVBoxLayout *progLayout = new QVBoxLayout;


    cPEdit = new QTextEdit;
    cPEdit->setMaximumWidth(210);


    fPEdit = new QTextEdit;
    fPEdit->setMaximumWidth(210);

    progLayout->addWidget(cPEdit);
    progLayout->addSpacing(15);
    progLayout->addWidget(fPEdit);
    progLayout->addStretch(0);

    QWidget *progWidget = new QWidget;
    progWidget->setLayout(progLayout);

    QHBoxLayout *layout = new QHBoxLayout;
    layout->addWidget(progWidget);

    QVBoxLayout *viewLayout = new QVBoxLayout;
    view = new QGraphicsView(scene);
    view->setRenderHint(QPainter::Antialiasing);
    viewLayout->addWidget(zoomSlider);
    viewLayout->addWidget(view);
    viewLayout->addWidget(rotateSlider);
    layout->addLayout(viewLayout);


    connect(zoomSlider, SIGNAL(valueChanged(int)), this, SLOT(setupMatrix()));
    connect(rotateSlider, SIGNAL(valueChanged(int)), this, SLOT(setupMatrix()));
    setupMatrix();

    QWidget *widget = new QWidget;
    widget->setLayout(layout);

    setCentralWidget(widget);
    setWindowTitle(tr("QAPMaker"));
}

void MainWindow::setupMenus()
{
    QMenu *fileMenu = menuBar()->addMenu(tr("&File"));

    QAction *openAction = fileMenu->addAction(tr("&Open..."));
    openAction->setShortcuts(QKeySequence::Open);

    QAction *exitAction = fileMenu->addAction(tr("E&xit"));
    exitAction->setShortcuts(QKeySequence::Quit);

    QMenu *gameMenu = menuBar()->addMenu(tr("&Game"));

    QAction *restartAction = gameMenu->addAction(tr("&Restart"));

//    connect(openAction, SIGNAL(triggered()), this, SLOT(openImage()));
//    connect(exitAction, SIGNAL(triggered()), qApp, SLOT(quit()));
//    connect(restartAction, SIGNAL(triggered()), this, SLOT(setupPuzzle()));
}

void MainWindow::setupWidgets()
{
    QFrame *frame = new QFrame;
    QVBoxLayout *frameLayout = new QVBoxLayout(frame);
    flatProg = new FlatProgram();

    cProg = new CProgram();


    frameLayout->addWidget(cProg);
    frameLayout->addWidget(flatProg);
    setCentralWidget(frame);
}

void MainWindow::setupMatrix()
{
    qreal scale = qPow(qreal(2), (zoomSlider->value() - 250) / qreal(50));

    QMatrix matrix;
    matrix.scale(scale, scale);
    matrix.rotate(rotateSlider->value());

    view->setMatrix(matrix);
}

void MainWindow::rotateLeft()
{
    rotateSlider->setValue(rotateSlider->value() - 10);
}

void MainWindow::rotateRight()
{
    rotateSlider->setValue(rotateSlider->value() + 10);
}
