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
#include "r1csscene.h"
#include "polyplot.h"
#include "qcustomplot.h"

#include <QtWidgets>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{

    setupMenus();

// set up the circuit scene
    scene = new CircuitScene(gateMenu, wireMenu, 800, 800, this);
    scene->setSceneRect(QRectF(0, 0, 800, 800));
    scene->setBackgroundBrush(Qt::lightGray);

//connect to circuitscene for selection/deselection signals
    connect(scene, SIGNAL(itemSelected(QGraphicsItem*)),
                this, SLOT(itemSelected(QGraphicsItem*)));
    connect(scene, SIGNAL(itemdeSelected(QGraphicsItem*)),
                this, SLOT(itemdeSelected(QGraphicsItem*)));

// set up the r1cs scene
    r1scene = new R1csScene(this);
    r1scene->setSceneRect(QRectF(0, 0, 400, 400));
    r1scene->setBackgroundBrush(Qt::lightGray);


//    cell = new QGraphicsRectItem;
//    cell->setRect(0, 0, 400, 400);
//    cell->setBrush(Qt::white);
//    cell->setZValue(-2000);

//    scene->addItem(cell);


// create a zoom slider for the circuit scene
    zoomSlider = new QSlider;
    zoomSlider->setOrientation(Qt::Horizontal);
    zoomSlider->setMinimum(0);
    zoomSlider->setMaximum(500);
    zoomSlider->setValue(250);


// program layouts and labels
    QVBoxLayout *progLayout = new QVBoxLayout;
    QHBoxLayout *cProgBar = new QHBoxLayout;
    QLabel *cProgLabel = new QLabel(tr("C Program"));
    cProgBar->addWidget(cProgLabel);

    QHBoxLayout *fProgBar = new QHBoxLayout;
    QLabel *fProgLabel = new QLabel(tr("Flattened Program"));
    fProgBar->addWidget(fProgLabel);
    QHBoxLayout *progInputBar = new QHBoxLayout;
    QLabel *progInputLabel = new QLabel(tr("Input"));
    progInputBar->addWidget(progInputLabel);
    QLabel *progOutputLabel = new QLabel(tr("Ouput"));

// edit boxes for the progams
    cProgEdit = new QTextEdit;
    cProgEdit->setMinimumWidth(320);
    cProgEdit->setMaximumWidth(320);
    cProgEdit->setMinimumHeight(260);
    cProgEdit->setMaximumHeight(260);

    fProgEdit = new QTextEdit;
    fProgEdit->setMinimumWidth(320);
    fProgEdit->setMaximumWidth(320);
    fProgEdit->setMinimumHeight(260);
    fProgEdit->setMaximumHeight(260);

    progInputEdit = new QTextEdit;
    progOutputEdit = new QTextEdit;

    progLayout->addLayout(cProgBar);
    progLayout->addWidget(cProgEdit);
    progLayout->addSpacing(15);
    progLayout->addLayout(fProgBar);
    progLayout->addWidget(fProgEdit);
    progLayout->addSpacing(15);
    progLayout->addLayout(progInputBar);
    progLayout->addWidget(progInputEdit);
    progLayout->addSpacing(15);
    progLayout->addWidget(progOutputLabel);
    progLayout->addWidget(progOutputEdit);
    progLayout->addStretch(0);

    QWidget *progWidget = new QWidget;
    progWidget->setLayout(progLayout);

    QHBoxLayout *layout = new QHBoxLayout;
    layout->addWidget(progWidget);

// Circuit scene layout
    QHBoxLayout *circuitBar = new QHBoxLayout;
    QLabel *circuitLabel = new QLabel(tr("Circuit"));
    circuitBar->addWidget(circuitLabel);

    QVBoxLayout *viewLayout = new QVBoxLayout;
    view = new QGraphicsView(scene);
    view->setRenderHint(QPainter::Antialiasing);
    view->setFixedSize(800,800);
    view->setSceneRect(0,0,800,800);
    viewLayout->addLayout(circuitBar);
    viewLayout->addWidget(view);
    viewLayout->addWidget(zoomSlider);
    layout->addLayout(viewLayout);

    connect(zoomSlider, SIGNAL(valueChanged(int)), this, SLOT(setupMatrix()));
    setupMatrix();

// R1CS and polynomial views
    QHBoxLayout *r1csBar = new QHBoxLayout;
    QLabel *r1csLabel = new QLabel(tr("R1CS"));
    r1csBar->addWidget(r1csLabel);


    pplot = new PolyPlot;
    QHBoxLayout *polyBar = new QHBoxLayout;
    QLabel *polyLabel = new QLabel(tr("Polynomial"));
    polyBar->addWidget(polyLabel);

    QVBoxLayout *r1viewLayout = new QVBoxLayout;
    r1view = new QGraphicsView(r1scene);
    r1view->setRenderHint(QPainter::Antialiasing);
    r1viewLayout->addLayout(r1csBar);
    r1viewLayout->addWidget(r1view);
    r1viewLayout->addSpacing(15);
    r1viewLayout->addLayout(polyBar);
    r1viewLayout->addWidget(pplot);

    layout->addSpacing(15);
    layout->addLayout(r1viewLayout);


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

    view->setMatrix(matrix);
}

