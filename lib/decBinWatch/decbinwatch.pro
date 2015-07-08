TEMPLATE = lib
TARGET = DecBinWatch
QT += qml quick
CONFIG += qt plugin

TARGET = $$qtLibraryTarget($$TARGET)
uri = ru.radiow.fury

# Input
SOURCES += \
    decbinwatch_plugin.cpp \
    decbinarywatch.cpp \
    watchmodel.cpp \
    qsgdecbinarywatch.cpp

HEADERS += \
    decbinwatch_plugin.h \
    decbinarywatch.h \
    watchmodel.h \
    qsgdecbinarywatch.h



