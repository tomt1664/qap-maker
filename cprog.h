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

class CProgram  // class for the main c program
{

public:
    CProgram();
    void loadSource(QStringList inSource);
    QStringList outSource();

protected:

private:
    QStringList source;
};

#endif // CPROG

