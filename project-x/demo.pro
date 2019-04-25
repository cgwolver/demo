#-------------------------------------------------
#
# Project created by QtCreator 2018-11-20T09:41:37
#
#-------------------------------------------------

QT       += core gui widgets quick quickwidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = 996icu
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

INCLUDEPATH += D:\Projects\demo\libqrencode-master \
                D:\Projects\demo\cpuid

CONFIG(debug,debug|release){
    LIBS += D:\Projects\demo\libqrencode-master\vs2017\Debug\qrencoded.lib \
        D:\Projects\demo\cpuid\x64\Debug\cpuid.lib
}
else{
    LIBS += D:\Projects\demo\libqrencode-master\vs2017\Release\qrencode.lib \
        D:\Projects\demo\cpuid\x64\Debug\cpuid.lib
}

SOURCES += \
        main.cpp \
        mainwindow.cpp \
    buttonlist.cpp \
    capbarevent.cpp \
    itembutton.cpp \
    buttontable.cpp \
    picturebox.cpp

HEADERS += \
    cpuid.h \
        mainwindow.h \
    buttonlist.h \
    capbarevent.h \
    itembutton.h \
    buttontable.h \
    picturebox.h

FORMS += \
        mainwindow.ui

DISTFILES +=

RESOURCES += \
    appres.qrc
