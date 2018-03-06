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
        inputVals.append(stringInt.toInt());
    }
}

//function to parse the input program and interpret it
QString CProgram::runProgram()
{
    QRegExp separator(" |,|{|}");

    //check input/output structs
    QString line = source[0];
    QStringList lineItems = line.split(separator);
    if(lineItems.size() < 4) return "Error: input struct incomplete";
    if(lineItems[0] != "struct" && lineItems[1] != "in") return "Error: missing input struct";
    ninputs = 0;
    for(int i=0;i<(lineItems.size()-1);i++)
    {
        if(lineItems[i] == "int")
        {
            ninputs++;
            inputVars.append(lineItems[i+1]);
        }
    }

    line = source[1];
    lineItems = line.split(separator);
    if(lineItems.size() < 4) return "Error: output struct incomplete";
    if(lineItems[0] != "struct" && lineItems[1] != "out") return "Error: missing ouput struct";
    noutputs = 0;
    for(int i=0;i<(lineItems.size()-1);i++)
    {
        if(lineItems[i] == "int")
        {
            noutputs++;
            outputVars.append(lineItems[i+1]);
        }
    }

    QString output;

    return QString::number(ninputs);
}
