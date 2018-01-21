/*************************************************************************************
** QAPMaker: An interactive tool for developing simple Quadratic Arithmetic Programs
**
** Built using Qt 5.6
**
** Tom Trevethan 2017
** tptrevethan@googlemail.com
**************************************************************************************/

#include "flatprog.h"

FlatProgram::FlatProgram(QWidget *parent)
    : QWidget(parent)
{

}

QSize FlatProgram::size() const
{
    return QSize(100, 100);
}
