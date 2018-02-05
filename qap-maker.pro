QT += widgets svg
qtHaveModule(printsupport): QT += printsupport

HEADERS	    =   mainwindow.h \
                qcustomplot.h \
    cprog.h \
    flatprog.h \
    circuitscene.h \
    r1csscene.h \
    polyplot.h

SOURCES	    =   mainwindow.cpp \
                qcustomplot.cpp \
                main.cpp \
    cprog.cpp \
    flatprog.cpp \
    circuitscene.cpp \
    r1csscene.cpp \
    polyplot.cpp

# install
target.path = /home/tt200/qap-maker/
INSTALLS += target
