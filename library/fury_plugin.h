#ifndef FURY_PLUGIN_H
#define FURY_PLUGIN_H

#include <QQmlExtensionPlugin>

class FuryPlugin : public QQmlExtensionPlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "org.qt-project.Qt.QQmlExtensionInterface")

public:
    void registerTypes(const char *uri);
};

#endif // FURY_PLUGIN_H

