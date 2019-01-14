QT -= gui

CONFIG += c++11 console
CONFIG -= app_bundle

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        main.cpp\
        src/portable/compat.c \
        src/portable/cmdmsg.c \
        src/cbatch.c \
        src/cchcp.c \
        src/cclock.c \
        src/cdata.c \
        src/cdebug.c \
        src/cenv.c \
        src/cext.c \
        src/cfile.c \
        src/cinfo.c \
        src/cinit.c \
        src/ckeys.c \
        src/clex.c \
        src/cmd.c \
        src/cmem.c \
        src/cop.c \
        src/console.c \
        src/cother.c \
        src/cparse.c \
        src/cpath.c \
        src/cpparse.c \
        src/cpwork.c \
        src/csig.c \
        src/ctools1.c \
        src/ctools2.c \
        src/ctools3.c \
        src/del.c   \
        src/dir.c \
        src/display.c \
        src/ffirst.c \
        src/hstoi.c \
        src/start.c \
        src/string.c \
        src/tree.c  \
        src/readcon.c \
        src/complete.c

INCLUDEPATH += ./src
INCLUDEPATH += ./src/cmd
INCLUDEPATH += ./src/portable
