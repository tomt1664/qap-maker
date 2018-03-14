/*************************************************************************************
** QAPMaker: An interactive tool for developing simple Quadratic Arithmetic Programs
**
** Built using Qt 5.6
**
** Tom Trevethan 2017
** tptrevethan@googlemail.com
**************************************************************************************/

#ifndef CPROG
#define CPROG

#include <QString>
#include <QStringList>
#include <QList>

class CProgram  // class for the main c program
{

public:
    CProgram();
    void loadSource(QStringList inSource);
    QStringList outSource();
    void loadInput(QString inputString);
    QString runProgram();

protected:

private:
    QStringList source;
    QList<int> inputVals;
    QList<int> outputVals;
    QStringList inputVars;
    QStringList outputVars;
    QStringList progVars;
    QList<int> progVals;
    int ninputs;
    int noutputs;
};

#endif // CPROG

