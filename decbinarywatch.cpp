#include "decbinarywatch.h"
#include "qsgdecbinarywatch.h"
#include <QSGSimpleRectNode>

DecBinaryWatch::DecBinaryWatch(QQuickItem *parent):
    QQuickItem(parent),
    on_color(250, 250, 250, 200),
    off_color(20, 20, 20, 200),
    invalidColor(true),
    map(0xffffff)
{
    setFlag(QQuickItem::ItemHasContents);
    m_time.setTime(QTime::currentTime());
    startTimer(1000);
}

QTime DecBinaryWatch::time() const
{
    return m_time.getTime();
}

void DecBinaryWatch::setTime(const QTime& time)
{

    map = m_time.setTime(time);
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
    quint8 i(0);
    QSGSimpleRectNode* digit;
    if (invalidColor)
    {
        for (i = 0; i < 24; ++i)
        {
            digit = static_cast<QSGSimpleRectNode*>(node->childAtIndex(i));
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
    else if (map)
    {
        for (i = 0; i < 24; ++i)
        {
            if (map & 1)
            {
                digit = static_cast<QSGSimpleRectNode*>(node->childAtIndex(i));
                if (c_time & 1)
                {
                    digit->setColor(on_color);
                }
                else
                {
                    digit->setColor(off_color);
                }
            }
            c_time >>= 1;
            map >>= 1;
        }
        map = 0;
    }
    return node;
}

void DecBinaryWatch::timerEvent(QTimerEvent *)
{
    setTime(QTime::currentTime());
}
