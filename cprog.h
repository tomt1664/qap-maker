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

#include <QWidget>
#include <QTextEdit>

class CProgram : public QWidget  // QWidget class for the main c program field
{
    Q_OBJECT

    QSize size() const Q_DECL_OVERRIDE;


public:

    CProgram(QWidget *parent = 0);

public slots:

protected:

private:

    QTextEdit *cProgEdit;
};

#endif // CPROG

