#include "decbinwatch_plugin.h"
#include "decbinarywatch.h"

#include <qqml.h>

void DecBinWatchPlugin::registerTypes(const char *uri)
{
    // @uri ru.radiow.fury
    qmlRegisterType<DecBinaryWatch>(uri, 0, 1, "DecBinaryWatch");
}


