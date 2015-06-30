#include "decbinarywatch.h"
#include <QSGSimpleRectNode>
#include <QtMath>
#include <QtDebug>

DecBinaryWatch::DecBinaryWatch(QQuickItem *parent):
    QQuickItem(parent),
    on_color(250, 250, 250, 200),
    off_color(20, 20, 20, 200),
    invalidColor(true),
    map(0xffffff)
{
    setFlag(QQuickItem::ItemHasContents);
    m_time.setTime(QTime::currentTime());
}

QTime DecBinaryWatch::time() const
{
    return m_time.getTime();
}

void DecBinaryWatch::setTime(const QTime& time)
{

    quint32 map = m_time.setTime(time);
    qDebug() << map;
    if (map)
    {
        update();
        emit timeChanged();
    }
}

QColor DecBinaryWatch::onColor() const
{
    return on_color;
}

void DecBinaryWatch::setOnColor(const QColor& color)
{
    if (color != on_color)
    {
        on_color = color;
        invalidColor = true;
        update();
    }
}

QColor DecBinaryWatch::offColor() const
{
    return off_color;
}

void DecBinaryWatch::setOffColor(const QColor& color)
{
    if (color != off_color)
    {
        off_color = color;
        invalidColor = true;
        update();
    }
}

QSGNode* DecBinaryWatch::updatePaintNode(QSGNode *oldNode, UpdatePaintNodeData *)
{
    QSGSimpleRectNode* node = static_cast<QSGSimpleRectNode*>(oldNode);
    if (!node)
    {
        node = new QSGSimpleRectNode();
    }
    if (m_time.getSum() & 1)
    {
        node->setColor(off_color);
    }
    else
    {
        node->setColor(on_color);
    }
    node->setRect(boundingRect());
    invalidColor = false;
    return node;
}

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
