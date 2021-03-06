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

LIBS += -lxml2

QT += websockets
QT += sql
QT += xmlpatterns

INCLUDEPATH += ./source \
               ./header

SOURCES += \
        source/main.cpp \
        source/server.cpp \
    source/client.cpp \
    source/action.cpp \
    source/dbcontroller.cpp \
    source/actiontienda.cpp \
    source/actiontecnico.cpp \
    source/actionadmin.cpp

HEADERS += \
    header/server.h \
    header/client.h \
    header/action.h \
    header/dbcontroller.h \
    header/actiontienda.h \
    header/actiontecnico.h \
    header/actionadmin.h

copydata.commands = $(COPY_DIR) $$PWD/XML $$OUT_PWD
first.depends = $(first) copydata
export(first.depends)
export(copydata.commands)
QMAKE_EXTRA_TARGETS += first copydata
