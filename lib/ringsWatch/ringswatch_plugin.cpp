#include "ringswatch_plugin.h"
#include "ringswatch.h"

#include <qqml.h>

void RingsWatchPlugin::registerTypes(const char *uri)
{
    // @uri com.mycompany.qmlcomponents
    qmlRegisterType<RingsWatch>(uri, 1, 0, "RingsWatch");
}


