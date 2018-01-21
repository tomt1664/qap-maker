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

#include <QtWidgets>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setupMenus();
    setupWidgets();

    setSizePolicy(QSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed));
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
