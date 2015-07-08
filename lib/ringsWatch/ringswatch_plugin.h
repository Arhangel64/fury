#ifndef RINGSWATCH_PLUGIN_H
#define RINGSWATCH_PLUGIN_H

#include <QQmlExtensionPlugin>

class RingsWatchPlugin : public QQmlExtensionPlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "org.qt-project.Qt.QQmlExtensionInterface")

public:
    void registerTypes(const char *uri);
};

#endif // RINGSWATCH_PLUGIN_H

