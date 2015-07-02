#include "decbinarywatch.h"
#include "qsgdecbinarywatch.h"
#include <QSGSimpleRectNode>
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
        qDebug() << m_time.getSum();
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
    QSGDecBinaryWatch* node = static_cast<QSGDecBinaryWatch*>(oldNode);
    if (!node)
    {
        node = new QSGDecBinaryWatch();
    }

    QRectF newBounds = boundingRect();
    if (oldBounds != newBounds)
    {
        node->setRect(newBounds);
        oldBounds = newBounds;
    }
    quint32 c_time = m_time.getSum();
    if (invalidColor)
    {
        for (quint8 i = 0; i < 24; ++i)
        {
            QSGSimpleRectNode* digit = static_cast<QSGSimpleRectNode*>(node->childAtIndex(i));
            if (c_time & 1)
            {
                digit->setColor(on_color);
            }
            else
            {
                digit->setColor(off_color);
            }
            c_time >>= 1;
        }
        invalidColor = false;
    }
    return node;
}
