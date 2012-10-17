######################################################################
# Automatically generated by qmake (2.01a) Wed Sep 5 17:30:24 2012
######################################################################

TEMPLATE = app
TARGET = 
DEPENDPATH += .
INCLUDEPATH += . external/cnpy

# Input
HEADERS += MainWindow.h PCAPlayer.h external/cnpy/cnpy.h \
    PCA.h \
    TimeSeries.h \
    Config.h \
    MathUtil.h \
    CVUtil.h
SOURCES += main.cpp MainWindow.cpp PCAPlayer.cpp external/cnpy/cnpy.cpp \
    PCA.cpp \
    TimeSeries.cpp \
    CVUtil.cpp

unix {
    CONFIG += link_pkgconfig
    PKGCONFIG += opencv
}

QT += opengl

OTHER_FILES +=
