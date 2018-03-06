/*************************************************************************************
** QAPMaker: An interactive tool for developing simple Quadratic Arithmetic Programs
**
** Built using Qt 5.6
**
** Tom Trevethan 2017
** tptrevethan@googlemail.com
**************************************************************************************/

#include "mainwindow.h"
#include "cprog.h"
#include "flatprog.h"
#include "circuitscene.h"
#include "r1csscene.h"
#include "polyplot.h"
#include "qcustomplot.h"

#include <QtWidgets>
#include <QDebug>
#include <QTextStream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{

//  initial set-up
    setupMenus();

// set up the circuit scene
    scene = new CircuitScene(gateMenu, wireMenu, 600, 800, this);
    scene->setSceneRect(QRectF(0, 0, 600, 800));
    scene->setBackgroundBrush(Qt::lightGray);

//connect to circuitscene for selection/deselection signals
    connect(scene, SIGNAL(itemSelected(QGraphicsItem*)),
                this, SLOT(itemSelected(QGraphicsItem*)));
    connect(scene, SIGNAL(itemdeSelected(QGraphicsItem*)),
                this, SLOT(itemdeSelected(QGraphicsItem*)));

// set up the r1cs scene
    r1scene = new R1csScene(this);
    r1scene->setSceneRect(QRectF(0, 0, 600, 320));
    r1scene->setBackgroundBrush(Qt::lightGray);

// create a zoom slider for the circuit scene
    zoomSlider = new QSlider;
    zoomSlider->setOrientation(Qt::Horizontal);
    zoomSlider->setMinimum(0);
    zoomSlider->setMaximum(500);
    zoomSlider->setValue(200);

// program layouts and labels
    QFont labelFont("Helvetica", 12, QFont::Bold);
//  buttons for the c program box
    cProgOpenButton = new QToolButton;
    cProgOpenButton->setIcon(QIcon(QPixmap(":/icons/folder.png")));
    cProgOpenButton->setIconSize(QSize(20, 20));
    cProgOpenButton->setToolTip("Open file");
    connect(cProgOpenButton, SIGNAL(clicked()),this,SLOT(openCFile()));

    cProgSaveButton = new QToolButton;
    cProgSaveButton->setIcon(QIcon(QPixmap(":/icons/save.png")));
    cProgSaveButton->setIconSize(QSize(20, 20));
    cProgSaveButton->setToolTip("Save file");
    connect(cProgSaveButton, SIGNAL(clicked()),this,SLOT(saveCFile()));

    cProgRunButton = new QToolButton;
    cProgRunButton->setIcon(QIcon(QPixmap(":/icons/play.png")));
    cProgRunButton->setIconSize(QSize(20, 20));
    cProgRunButton->setToolTip("Run program");
    connect(cProgRunButton, SIGNAL(clicked()),this,SLOT(runCProg()));

    cProgFlatButton = new QToolButton;
    cProgFlatButton->setIcon(QIcon(QPixmap(":/icons/flat2.png")));
    cProgFlatButton->setIconSize(QSize(20, 20));
    cProgFlatButton->setToolTip("Flatten program");

    QVBoxLayout *progLayout = new QVBoxLayout;
    QHBoxLayout *cProgBar = new QHBoxLayout;
    QLabel *cProgLabel = new QLabel(tr("C Program"));
    cProgLabel->setFont(labelFont);
    cProgBar->addWidget(cProgLabel);
    cProgBar->addWidget(cProgOpenButton);
    cProgBar->addWidget(cProgSaveButton);
    cProgBar->addWidget(cProgRunButton);
    cProgBar->addWidget(cProgFlatButton);

// buttons for the Flattened program box

    fProgOpenButton = new QToolButton;
    fProgOpenButton->setIcon(QIcon(QPixmap(":/icons/folder.png")));
    fProgOpenButton->setIconSize(QSize(20, 20));
    fProgOpenButton->setToolTip("Open file");

    fProgSaveButton = new QToolButton;
    fProgSaveButton->setIcon(QIcon(QPixmap(":/icons/save.png")));
    fProgSaveButton->setIconSize(QSize(20, 20));
    fProgSaveButton->setToolTip("Save file");

    fProgRunButton = new QToolButton;
    fProgRunButton->setIcon(QIcon(QPixmap(":/icons/play.png")));
    fProgRunButton->setIconSize(QSize(20, 20));
    fProgRunButton->setToolTip("Run program");

    fProgCircuitButton = new QToolButton;
    fProgCircuitButton->setIcon(QIcon(QPixmap(":/icons/circuit.png")));
    fProgCircuitButton->setIconSize(QSize(20, 20));
    fProgCircuitButton->setToolTip("Create circuit");

    QHBoxLayout *fProgBar = new QHBoxLayout;
    QLabel *fProgLabel = new QLabel(tr("Flattened Program"));
    fProgLabel->setFont(labelFont);
    fProgBar->addWidget(fProgLabel);
    fProgBar->addWidget(fProgOpenButton);
    fProgBar->addWidget(fProgSaveButton);
    fProgBar->addWidget(fProgRunButton);
    fProgBar->addWidget(fProgCircuitButton);

    QHBoxLayout *progInputBar = new QHBoxLayout;
    QLabel *progInputLabel = new QLabel(tr("Input"));
    progInputLabel->setFont(labelFont);
    progInputBar->addWidget(progInputLabel);
    QLabel *progOutputLabel = new QLabel(tr("Ouput"));
    progOutputLabel->setFont(labelFont);

// edit boxes for the progams
    cProgEdit = new QTextEdit;
    cProgEdit->setMinimumWidth(320);
    cProgEdit->setMaximumWidth(320);
    cProgEdit->setMinimumHeight(260);
    cProgEdit->setMaximumHeight(260);

    fProgEdit = new QTextEdit;
    fProgEdit->setMinimumWidth(320);
    fProgEdit->setMaximumWidth(320);
    fProgEdit->setMinimumHeight(260);
    fProgEdit->setMaximumHeight(260);

    progInputEdit = new QTextEdit;
    progOutputEdit = new QTextEdit;

    progLayout->addLayout(cProgBar);
    progLayout->addWidget(cProgEdit);
    progLayout->addSpacing(15);
    progLayout->addLayout(fProgBar);
    progLayout->addWidget(fProgEdit);
    progLayout->addSpacing(15);
    progLayout->addLayout(progInputBar);
    progLayout->addWidget(progInputEdit);
    progLayout->addSpacing(15);
    progLayout->addWidget(progOutputLabel);
    progLayout->addWidget(progOutputEdit);
    progLayout->addStretch(0);

    QWidget *progWidget = new QWidget;
    progWidget->setLayout(progLayout);

    QHBoxLayout *layout = new QHBoxLayout;
    layout->addWidget(progWidget);
    layout->addSpacing(20);

// Circuit scene layout

    //circuit buttons
    circuitSaveButton = new QToolButton;
    circuitSaveButton->setIcon(QIcon(QPixmap(":/icons/save.png")));
    circuitSaveButton->setIconSize(QSize(20, 20));
    circuitSaveButton->setToolTip("Save circuit");

    circuitImageButton = new QToolButton;
    circuitImageButton->setIcon(QIcon(QPixmap(":/icons/image.png")));
    circuitImageButton->setIconSize(QSize(20, 20));
    circuitImageButton->setToolTip("Export image");

    circuitSettingsButton = new QToolButton;
    circuitSettingsButton->setIcon(QIcon(QPixmap(":/icons/settings.png")));
    circuitSettingsButton->setIconSize(QSize(20, 20));
    circuitSettingsButton->setToolTip("Save circuit");

    circuitR1CSButton = new QToolButton;
    circuitR1CSButton->setIcon(QIcon(QPixmap(":/icons/export.png")));
    circuitR1CSButton->setIconSize(QSize(20, 20));
    circuitR1CSButton->setToolTip("Create R1CS");

    QHBoxLayout *circuitBar = new QHBoxLayout;
    QLabel *circuitLabel = new QLabel(tr("Circuit"));
    circuitLabel->setFont(labelFont);
    circuitBar->addWidget(circuitLabel);
    circuitBar->addWidget(circuitSaveButton);
    circuitBar->addWidget(circuitImageButton);
    circuitBar->addWidget(circuitSettingsButton);
    circuitBar->addWidget(circuitR1CSButton);

    QVBoxLayout *viewLayout = new QVBoxLayout;
    view = new QGraphicsView(scene);
    view->setRenderHint(QPainter::Antialiasing);
    view->setFixedSize(600,800);
    view->setSceneRect(0,0,600,800);
    viewLayout->addSpacing(10);
    viewLayout->addLayout(circuitBar);
    viewLayout->addWidget(view);
    viewLayout->addWidget(zoomSlider);
    layout->addLayout(viewLayout);

    connect(zoomSlider, SIGNAL(valueChanged(int)), this, SLOT(setupMatrix()));
    setupMatrix();

// R1CS and polynomial views
    QHBoxLayout *r1csBar = new QHBoxLayout;
    QLabel *r1csLabel = new QLabel(tr("R1CS"));
    r1csLabel->setFont(labelFont);
    r1csBar->addWidget(r1csLabel);


    pplot = new PolyPlot;
    QHBoxLayout *polyBar = new QHBoxLayout;
    QLabel *polyLabel = new QLabel(tr("Polynomial"));
    polyLabel->setFont(labelFont);
    polyBar->addWidget(polyLabel);

    QVBoxLayout *r1viewLayout = new QVBoxLayout;
    r1view = new QGraphicsView(r1scene);
    r1view->setRenderHint(QPainter::Antialiasing);
    r1view->setFixedSize(600,320);
    r1view->setSceneRect(0,0,600,320);
    r1view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    r1view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    r1viewLayout->addSpacing(15);
    r1viewLayout->addLayout(r1csBar);
    r1viewLayout->addWidget(r1view);
    r1viewLayout->addSpacing(15);
    r1viewLayout->addLayout(polyBar);
    r1viewLayout->addWidget(pplot);

    layout->addSpacing(25);
    layout->addLayout(r1viewLayout);


    QWidget *widget = new QWidget;
    widget->setLayout(layout);

    setCentralWidget(widget);
    setWindowTitle(tr("QAPMaker"));

    //declare program
    cProg = new CProgram;
}

void MainWindow::setupMenus()
{
    QMenu *progMenu = menuBar()->addMenu(tr("&Program"));

    QAction *openAction = progMenu->addAction(tr("&Open..."));
    openAction->setShortcuts(QKeySequence::Open);
    connect(openAction, SIGNAL(triggered()), this, SLOT(openCFile()));

    QAction *saveAction = progMenu->addAction(tr("&Save..."));
    saveAction->setShortcuts(QKeySequence::Save);

    QAction *runAction = progMenu->addAction(tr("&Run"));
    QAction *flattenAction = progMenu->addAction(tr("&Flatten"));

    QAction *exitAction = progMenu->addAction(tr("E&xit"));
    exitAction->setShortcuts(QKeySequence::Quit);

    QMenu *circuitMenu = menuBar()->addMenu(tr("&Circuit"));

    QAction *createAction = circuitMenu->addAction(tr("&Create"));
    QAction *csaveAction = circuitMenu->addAction(tr("&Save..."));
    QAction *exportAction = circuitMenu->addAction(tr("&Export..."));
    QAction *settingsAction = circuitMenu->addAction(tr("&Settings..."));

    QMenu *qapMenu = menuBar()->addMenu(tr("&QAP"));

    QAction *qapCreateAction = qapMenu->addAction(tr("&Create"));
    QAction *qapExportAction = qapMenu->addAction(tr("&Export..."));

    QMenu *helpMenu = menuBar()->addMenu(tr("&Help"));

    QAction *aboutAction = helpMenu->addAction(tr("&About"));
    QAction *guideAction = helpMenu->addAction(tr("&Guide..."));

    connect(saveAction, SIGNAL(triggered()), this, SLOT(saveCFile()));
    connect(aboutAction, SIGNAL(triggered()), this, SLOT(about()));
}

void MainWindow::setupMatrix()
{
    qreal scale = qPow(qreal(2), (zoomSlider->value() - 250) / qreal(50));

    QMatrix matrix;
    matrix.scale(scale, scale);

    view->setMatrix(matrix);
}

//function to open file dialog and save the c program
void MainWindow::saveCFile()
{
    QString savefile = QFileDialog::getSaveFileName(this, "Save C source",
                                                    QString(),
                                                    "C Files (*.c)");

    if (!savefile.isNull()) {

        QFile sfile(savefile);
        if (sfile.open(QFile::WriteOnly | QFile::Truncate))
        {
            QTextStream out(&sfile);
            QStringList outProg;
            outProg = cProg->outSource();
            foreach (QString line, outProg) {
                            out << line << "\n";
                        }

            sfile.close();
        } else
        {
            QMessageBox msgbox;
            msgbox.setText("Error writing C file");
            msgbox.exec();
            return;
        }
    } else
    {
        QMessageBox msgbox;
        msgbox.setText("Error writing C file");
        msgbox.exec();
        return;
    }


}

//about program box
void MainWindow::about()
{
    QMessageBox::about(this, tr("About "),
            tr("<p><b>QAP Maker 0.11</b></p>"
               "<br> "
               "<p>Build date: %1"
               "<br> "
               "<br>This program is built using Qt 5.6"
               "<br> "
               "<br>Tom Trevethan"
               "<br>Email: <a href=\"mailto:tptrevethan@googlemail.com>\">tptrevethan@googlemail.com</a>"
               "</p>").arg(__TIMESTAMP__));
}

//open c program and load
void MainWindow::openCFile()
{
    QString inputfile = QFileDialog::getOpenFileName(this, "Open C Source File",
                                                    QString(),
                                                    "C Source Files (*.c)");

    if (!inputfile.isNull()) {

        QFile file(inputfile);

        if (!file.open(QFile::ReadOnly | QFile::Text)) {
            QMessageBox msgbox;
            msgbox.setText("Error reading source file");
            msgbox.exec();
            return;
        }

        QTextStream tStream(&file);
        QStringList source;
        while (true)
        {
            QString line = tStream.readLine();
            if (line.isNull())
                break;
            else
                source.append(line);
        }

        cProgEdit->setCurrentFont(QFont("Courier",10));
        cProg->loadSource(source);
        foreach (QString line, source) {
                cProgEdit->append(line);
            }
    }
}

void MainWindow::flattenCProg()
{

}

void MainWindow::runCProg()
{
    //update source
    QString sourceString = cProgEdit->toPlainText();
    QStringList sourceLines = sourceString.split("\n");
    cProg->loadSource(sourceLines);

    // get the input
    QString getInput = progInputEdit->toPlainText();
    cProg->loadInput(getInput);

    QString getOutput = cProg->runProgram();
    progOutputEdit->append(getOutput);
}
