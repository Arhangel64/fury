#ifndef WATCHMODEL_H
#define WATCHMODEL_H

#include <QTime>

class WatchModel
{
public:
    WatchModel();

    quint32 setTime(const QTime&);
    QTime getTime() const;

    quint32 getSum() const;

private:
    quint32 sum;
    quint8 hh;
    quint8 hl;
    quint8 mh;
    quint8 ml;
    quint8 sh;
    quint8 sl;
};

#endif // WATCHMODEL_H
