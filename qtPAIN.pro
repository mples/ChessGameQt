#-------------------------------------------------
#
# Project created by QtCreator 2018-11-25T21:11:33
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = qtPAIN
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
    chesstablewindow.cpp \
    settingswindow.cpp \
    chesstablewidget.cpp \
    figure.cpp \
    pawn.cpp \
    rook.cpp \
    knight.cpp \
    bishop.cpp \
    king.cpp \
    queen.cpp \
    chessboard.cpp \
    menuwindow.cpp \
    endgamedialog.cpp

HEADERS += \
    chesstablewindow.h \
    settingswindow.h \
    chesstablewidget.h \
    figure.h \
    pawn.h \
    rook.h \
    knight.h \
    bishop.h \
    king.h \
    queen.h \
    chess_const.h \
    chessboard.h \
    menuwindow.h \
    endgamedialog.h

FORMS += \
    chesstablewindow.ui \
    settingswindow.ui \
    endgamedialog.ui \
    menuwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc
