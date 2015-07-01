#include "watchmodel.h"
#include <QtMath>

WatchModel::WatchModel():
    hh(0),
    hl(0),
    mh(0),
    ml(0),
    sh(0),
    sl(0)
{
}

quint32 WatchModel::setTime(const QTime& time)
{
    quint8 lhh(qFloor(time.hour() / 10));
    quint8 lhl(time.hour() % 10);
    quint8 lmh(qFloor(time.minute() / 10));
    quint8 lml(time.minute() % 10);
    quint8 lsh(qFloor(time.second() / 10));
    quint8 lsl(time.second() % 10);

    quint32 lsum = lsl | (lsh << 4) | (lml << 8) | (lmh << 12) | (lhl << 16) | (lhh << 24);

    quint32 esum = ~(~(lsum | sum) | (lsum & sum));
    if (esum)
    {
        hh = lhh;
        hl = lhl;
        mh = lmh;
        ml = lml;
        sh = lsh;
        sl = lsl;

        sum = lsum;
    }
    return esum;
}

QTime WatchModel::getTime() const
{
    return QTime(hh*10+hl, mh*10+ml, sh*10+sl);
}

quint32 WatchModel::getSum() const
{
    return sum;
}
