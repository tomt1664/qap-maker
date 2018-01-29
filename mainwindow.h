/*************************************************************************************
** QAPMaker: An interactive tool for developing simple Quadratic Arithmetic Programs
**
** Built using Qt 5.6
**
** Tom Trevethan 2017
** tptrevethan@googlemail.com
**************************************************************************************/

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QtWidgets>

class CProgram;
class FlatProgram;
class CircuitScene;

QT_BEGIN_NAMESPACE
class QAction;
class QToolBox;
class QSpinBox;
class QComboBox;
class QFontComboBox;
class QButtonGroup;
class QLineEdit;
class QGraphicsTextItem;
class QFont;
class QToolButton;
class QAbstractButton;
class QGraphicsView;
class QSlider;
QT_END_NAMESPACE
class CurveDisplay;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);

private slots:
    void setupMatrix();
    void rotateLeft();
    void rotateRight();

private:
    void setupMenus();
    void setupWidgets();

    CProgram *cProg;
    FlatProgram *flatProg;

    //mainwindow components
    QGraphicsRectItem *cell;
    CircuitScene *scene;
    QGraphicsView *view;
    QSlider *zoomSlider;
    QSlider *rotateSlider;

    //periodic images
    int xcell; // x cell dimension
    int ycell; // y cell dimension

    QTextEdit *cProgEdit;
    QTextEdit *fProgEdit;
    QTextEdit *progInputEdit;
    QTextEdit *progOutputEdit;

    QMenu *gateMenu;
    QMenu *wireMenu;
};

#endif // MAINWINDOW_H
