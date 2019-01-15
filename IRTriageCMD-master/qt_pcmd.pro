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
INCLUDEPATH += ./pcmd
SOURCES += \
        pcmd/alias.c\
        pcmd/assoc.c\
        pcmd/attrib.c\
        pcmd/batch.c\
        pcmd/beep.c\
        pcmd/call.c\
        pcmd/chcp.c\
        pcmd/choice.c\
        pcmd/cls.c\
        pcmd/cmd.c\
        pcmd/cmddbg.c\
        pcmd/cmdinput.c\
        pcmd/cmdtable.c\
        pcmd/color.c\
        pcmd/console.c\
        pcmd/copy.c\
        pcmd/date.c\
        pcmd/del.c\
        pcmd/delay.c\
        pcmd/dir.c\
        pcmd/dirstack.c\
        pcmd/echo.c\
        pcmd/error.c\
        pcmd/filecomp.c\
        pcmd/for.c\
        pcmd/free.c\
        pcmd/goto.c\
        pcmd/history.c\
        pcmd/if.c\
        pcmd/internal.c\
        pcmd/label.c\
        pcmd/locale.c\
        pcmd/memory.c\
        pcmd/misc.c\
        pcmd/mklink.c\
        pcmd/move.c\
        pcmd/msgbox.c\
        pcmd/parser.c\
        pcmd/path.c\
        pcmd/pause.c\
        pcmd/prompt.c\
        pcmd/redir.c\
        pcmd/ren.c\
        pcmd/replace.c\
        pcmd/screen.c\
        pcmd/set.c\
        pcmd/setlocal.c\
        pcmd/shift.c\
        pcmd/start.c\
        pcmd/strtoclr.c\
        pcmd/time.c\
        pcmd/timer.c\
        pcmd/title.c\
        pcmd/type.c\
        pcmd/ver.c\
        pcmd/verify.c\
        pcmd/vol.c\
        pcmd/where.c\
        pcmd/window.c\
        pcmd/precomp.h \
    qt_main.cpp \
    pcmd/precomp.c
