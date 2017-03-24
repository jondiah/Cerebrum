#-------------------------------------------------
#
# Project created by QtCreator 2017-03-23T12:41:22
#
#-------------------------------------------------

QT       += core gui multimedia multimediawidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Cerebrum
TEMPLATE = app


SOURCES += main.cpp\
        startupview.cpp \
    cameradevices.cpp \
    camera.cpp \
    camerahandler.cpp

HEADERS  += startupview.h \
    cameradevices.h \
    camera.h \
    camerahandler.h

FORMS    += startupview.ui
