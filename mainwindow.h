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
class R1csScene;
class PolyPlot;

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

private:
    void setupMenus();
    void setupWidgets();

    CProgram *cProg;
    FlatProgram *flatProg;

    //mainwindow components
    QGraphicsRectItem *cell;
    CircuitScene *scene;
    R1csScene *r1scene;
    QGraphicsView *view;
    QGraphicsView *r1view;
    QSlider *zoomSlider;
    PolyPlot *pplot;

    //program text edit boxes
    QTextEdit *cProgEdit;
    QTextEdit *fProgEdit;
    QTextEdit *progInputEdit;
    QTextEdit *progOutputEdit;

    //mainwindow buttons
    QToolButton *cProgOpenButton;
    QToolButton *cProgSaveButton;
    QToolButton *fProgSaveButton;
    QToolButton *cProgRunButton;
    QToolButton *cProgFlatButton;
    QToolButton *fProgCircuitButton;
    QToolButton *fProgOpenButton;
    QToolButton *fProgRunButton;
    QToolButton *circuitSaveButton;
    QToolButton *circuitImageButton;
    QToolButton *circuitSettingsButton;
    QToolButton *circuitR1CSButton;

    QMenu *gateMenu;
    QMenu *wireMenu;
};

#endif // MAINWINDOW_H
