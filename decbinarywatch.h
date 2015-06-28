#ifndef DECBINARYWATCH_H
#define DECBINARYWATCH_H

#include <QQuickItem>

class DecBinaryWatch : public QQuickItem
{
    Q_OBJECT
    Q_DISABLE_COPY(DecBinaryWatch)

public:
    DecBinaryWatch(QQuickItem *parent = 0);
    ~DecBinaryWatch();
};

#endif // DECBINARYWATCH_H

