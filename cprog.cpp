/*************************************************************************************
** QAPMaker: An interactive tool for developing simple Quadratic Arithmetic Programs
**
** Built using Qt 5.6
**
** Tom Trevethan 2017
** tptrevethan@googlemail.com
**************************************************************************************/

#include "cprog.h"

#include <QDebug>

CProgram::CProgram()
{

}

void CProgram::loadSource(QString inSource)
{
    source = inSource;
}

void CProgram::printSource()
{
    qDebug() << qPrintable(source);
}
