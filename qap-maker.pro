QT += widgets svg
qtHaveModule(printsupport): QT += printsupport

HEADERS	    =   mainwindow.h \
                qcustomplot.h \
    cprog.h \
    flatprog.h \
    circuitscene.h

SOURCES	    =   mainwindow.cpp \
                qcustomplot.cpp \
                main.cpp \
    cprog.cpp \
    flatprog.cpp \
    circuitscene.cpp

# install
target.path = /home/tt200/qap-maker/
INSTALLS += target
