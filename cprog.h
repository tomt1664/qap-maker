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

class CProgram  // class for the main c program
{

public:
    CProgram();
    void loadSource(QString inSource);
    void printSource();

protected:

private:
    QString source;
};

#endif // CPROG

