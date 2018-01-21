QT += widgets svg
qtHaveModule(printsupport): QT += printsupport

HEADERS	    =   mainwindow.h \
                qcustomplot.h \
    cprog.h \
    flatprog.h

SOURCES	    =   mainwindow.cpp \
                qcustomplot.cpp \
                main.cpp \
    cprog.cpp \
    flatprog.cpp

# install
target.path = /home/tt200/qap-maker/
INSTALLS += target
