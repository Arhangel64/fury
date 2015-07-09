#ifndef QSGDECBINARYWATCH_H
#define QSGDECBINARYWATCH_H

#include <QSGSimpleRectNode>
#include <QColor>
#include <QRectF>

class QSGDecBinaryWatch: public QSGSimpleRectNode
{
public:
    QSGDecBinaryWatch();

    void setRect(const QRectF &rect);
};

#endif // QSGDECBINARYWATCH_H
