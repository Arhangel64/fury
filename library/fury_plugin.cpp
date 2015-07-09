#include "fury_plugin.h"
#include "decbinarywatch.h"
#include "ringswatch.h"

#include <qqml.h>

void FuryPlugin::registerTypes(const char *uri)
{
    // @uri ru.radiow.fury
    qmlRegisterType<DecBinaryWatch>(uri, 0, 1, "DecBinaryWatch");
    qmlRegisterType<RingsWatch>(uri, 0, 1, "RingsyWatch");
}


