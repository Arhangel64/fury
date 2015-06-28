#include "decbinwatch_plugin.h"
#include "decbinarywatch.h"

#include <qqml.h>

void DecBinWatchPlugin::registerTypes(const char *uri)
{
    // @uri org.kde.plasma.W
    qmlRegisterType<DecBinaryWatch>(uri, 1, 0, "DecBinaryWatch");
}


