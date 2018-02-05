/*************************************************************************************
** QAPMaker: An interactive tool for developing simple Quadratic Arithmetic Programs
**
** Built using Qt 5.6
**
** Tom Trevethan 2017
** tptrevethan@googlemail.com
**************************************************************************************/

#ifndef POLYPLOT_H
#define POLYPLOT_H

#include <QDialog>
#include <QtWidgets>
#include <QLineEdit>
#include <qcustomplot.h>

class PolyPlot : public QWidget   // plotting graph for simulation output
{
    Q_OBJECT

public:
    PolyPlot();

private slots:
    void saveButtonPress();
    void exportButtonPress();
    void cancelButtonPress();
    void setPlotType();

private:
    QPushButton *saveButton;
    QPushButton *cancelButton;
    QPushButton *exportButton;
    QComboBox *plotType;
    QCustomPlot *customPlot;
};

#endif // POLYPLOT_H

