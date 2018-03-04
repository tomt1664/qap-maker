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

void CProgram::loadSource(QStringList inSource)
{
    source = inSource;
}

QStringList CProgram::outSource()
{
    return source;
}

void CProgram::loadInput(QString inputString)
{
    QStringList intList = inputString.split(" ",QString::SkipEmptyParts);

    foreach(QString stringInt, intList)
    {
        inputs.append(stringInt.toInt());
    }
}

QString CProgram::runProgram()
{
    QString output;

    foreach(int outValue, inputs)
    {
        output += outValue;
    }

    return output;
}
