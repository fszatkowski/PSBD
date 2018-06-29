#-------------------------------------------------
#
# Project created by QtCreator 2018-06-18T13:15:57
#
#-------------------------------------------------

QT += core gui
QT += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = PSBD
TEMPLATE = app

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
    mainwindow.cpp \
    loginwindow.cpp \
    adminmainwindow.cpp \
    adminraports.cpp \
    adminaddtoclasses.cpp \
    searchwindow.cpp \
    portiermainwindow.cpp \
    portieraddvisit.cpp \
    studentmainwindow.cpp \
    studentattendance.cpp \
    raportspopular.cpp \
    raportsrushhour.cpp \
    raportspasses.cpp

HEADERS += \
    mainwindow.h \
    loginwindow.h \
    adminmainwindow.h \
    adminraports.h \
    adminaddtoclasses.h \
    searchwindow.h \
    portiermainwindow.h \
    portieraddvisit.h \
    studentmainwindow.h \
    studentattendance.h \
    raportspopular.h \
    raportsrushhour.h \
    raportspasses.h

FORMS += \
    mainwindow.ui \
    loginwindow.ui \
    adminmainwindow.ui \
    adminraports.ui \
    adminaddtoclasses.ui \
    searchwindow.ui \
    portiermainwindow.ui \
    portieraddvisit.ui \
    studentmainwindow.ui \
    studentattendance.ui \
    raportspopular.ui \
    raportsrushhour.ui \
    raportspasses.ui

win32: LIBS += -L$$PWD/./ -llibmysql

INCLUDEPATH += $$PWD/.
DEPENDPATH += $$PWD/.
