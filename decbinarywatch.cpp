#include "decbinarywatch.h"
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
