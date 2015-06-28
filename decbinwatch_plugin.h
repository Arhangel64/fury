#ifndef DECBINWATCH_PLUGIN_H
#define DECBINWATCH_PLUGIN_H

#include <QQmlExtensionPlugin>

class DecBinWatchPlugin : public QQmlExtensionPlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "org.qt-project.Qt.QQmlExtensionInterface")

public:
    void registerTypes(const char *uri);
};

#endif // DECBINWATCH_PLUGIN_H

