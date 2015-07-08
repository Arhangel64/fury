#ifndef RINGSWATCH_H
#define RINGSWATCH_H

#include <QQuickItem>

class RingsWatch : public QQuickItem
{
    Q_OBJECT
    Q_DISABLE_COPY(RingsWatch)

public:
    RingsWatch(QQuickItem *parent = 0);
    ~RingsWatch();
};

#endif // RINGSWATCH_H

