/*************************************************************************************
** QAPMaker: An interactive tool for developing simple Quadratic Arithmetic Programs
**
** Built using Qt 5.6
**
** Tom Trevethan 2017
** tptrevethan@googlemail.com
**************************************************************************************/

#include "cprog.h"

#include <QMainWindow>
#include <QWidget>
#include <QtWidgets>

CProgram::CProgram(QWidget *parent)
    : QWidget(parent)
{

    QVBoxLayout *cLayout = new QVBoxLayout;

    cProgEdit = new QTextEdit;
    cProgEdit->setReadOnly(true);
    cProgEdit->setBackgroundRole(QPalette::NoRole);
    cProgEdit->setMaximumWidth(210);
    cProgEdit->append("Hello");

    cLayout->addWidget(cProgEdit);

    QWidget *cWidget = new QWidget;
    cWidget->setLayout(cLayout);

}
