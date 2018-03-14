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
    QRegExp separator(" |,|{|}|;");
    QRegExp number("\\d*");

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

    //read in compute function
    line = source[2];
    if(line != "void compute(struct In, struct Out)") return "Error: missing compute function";
    line = source[3];
    if(line != "{") "Error: malformed compute function";

    //loop over compute sequence
    for(int i = 1; i<200; i++)
    {
        if(i+3 >= source.size()) return "Error: compute function missing closing brace";
        line = source[i+3];
        if(line == "}") break;

        lineItems = line.split(separator);

        if(lineItems[0] == "int")
        {
            if(lineItems.size()<2) return "Error: invalid integer declaration";
            for(int j=1;j<(lineItems.size()-1);j++)
            {
                progVars.append(lineItems[j]);
            }
        } else if(progVars.contains(lineItems[0]) || inputVars.contains(lineItems[0]) || outputVars.contains(lineItems[0]))
        {
            if(lineItems[1] != "=") return "Error: invalid arithmetic operation";

            //assign integer values
            if(number.exactMatch(lineItems[2]))
            {

            }


        } else
        {
            return "Error: undeclaired variable";
        }



        for(int i=0;i<(lineItems.size()-1);i++)
        {
            if(lineItems[1] == "int")
            {
                noutputs++;
                outputVars.append(lineItems[i+1]);
            }
        }

    }



    QString output;

    return QString::number(ninputs);
}
