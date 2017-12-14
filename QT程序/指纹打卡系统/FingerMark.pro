#-------------------------------------------------
#
# Project created by QtCreator 2017-10-11T14:20:00
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = FingerMark
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        MainWin.cpp \
    FingerRecord.cpp \
    ArriveCheck.cpp \
    SystemManager.cpp \
    Password.cpp \
    Sql/FingerBase.cpp \
    AddSchedule.cpp \
    AddDialog.cpp \
    mylineedit.cpp \
    keyboard.cpp \
    newpassword.cpp

HEADERS += \
        MainWin.h \
    FingerRecord.h \
    ArriveCheck.h \
    SystemManager.h \
    Password.h \
    Sql/FingerBase.h \
    AddSchedule.h \
    AddDialog.h \
    mylineedit.h \
    keyboard.h \
    newpassword.h

FORMS += \
        MainWin.ui \
    FingerRecord.ui \
    ArriveCheck.ui \
    SystemManager.ui \
    Password.ui \
    AddSchedule.ui \
    AddDialog.ui \
    keyboard.ui \
    newpassword.ui

RESOURCES += \
    finger.qrc
