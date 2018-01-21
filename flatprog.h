/*************************************************************************************
** QAPMaker: An interactive tool for developing simple Quadratic Arithmetic Programs
**
** Built using Qt 5.6
**
** Tom Trevethan 2017
** tptrevethan@googlemail.com
**************************************************************************************/

#ifndef FLATPROG
#define FLATPROG

#include <QWidget>

class FlatProgram : public QWidget  // QWidget class for the flattened program field
{
    Q_OBJECT

    QSize size() const Q_DECL_OVERRIDE;

public:

    FlatProgram(QWidget *parent = 0);

public slots:

protected:

private:

};

#endif // FLATPROG

