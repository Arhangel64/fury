#include "decbinarywatch.h"
#include <QSGSimpleRectNode>

DecBinaryWatch::DecBinaryWatch(QQuickItem *parent):
    QQuickItem(parent),
    m_full(250, 250, 250, 200),
    m_empty(20, 20, 20, 200),
    m_time(QTime::currentTime())
{
    setFlag(QQuickItem::ItemHasContents);
}

QTime DecBinaryWatch::time() const
{
    return m_time;
}

void DecBinaryWatch::setTime(const QTime& time)
{
    if (time != m_time)
    {
        m_time = time;
        update();
        emit timeChanged();
    }
}

QSGNode* DecBinaryWatch::updatePaintNode(QSGNode *oldNode, UpdatePaintNodeData *)
{
    QSGSimpleRectNode* node = static_cast<QSGSimpleRectNode*>(oldNode);
    if (!node)
    {
        node = new QSGSimpleRectNode();
    }
    if (time().second()%2 == 0)
    {
        node->setColor(m_empty);
    }
    else
    {
        node->setColor(m_full);
    }
    node->setRect(boundingRect());
    return node;
}
