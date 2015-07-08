TEMPLATE = lib
TARGET = RingsWatch
QT += qml quick
CONFIG += qt plugin

TARGET = $$qtLibraryTarget($$TARGET)
uri = ru.radiow.fury

# Input
SOURCES += \
    ringswatch_plugin.cpp \
    ringswatch.cpp

HEADERS += \
    ringswatch_plugin.h \
    ringswatch.h
