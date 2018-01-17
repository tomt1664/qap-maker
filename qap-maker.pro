QT += widgets svg
qtHaveModule(printsupport): QT += printsupport

HEADERS	    =   mainwindow.h \
                qcustomplot.h

SOURCES	    =   mainwindow.cpp \
                qcustomplot.cpp \
                main.cpp

# install
target.path = /home/tt200/qap-maker/
INSTALLS += target
