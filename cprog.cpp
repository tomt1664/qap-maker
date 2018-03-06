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
    source.clear();
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

//function to parse the input program and interpret it
QString CProgram::runProgram()
{
    QString output2;

    //check input and ouput structs
    foreach(QString line, source)
    {
        output2 = line;
    }

    QString output;

    foreach(int outValue, inputs)
    {
        output += QString::number(outValue) + " ";
    }

    return QString::number(source.size());
}
