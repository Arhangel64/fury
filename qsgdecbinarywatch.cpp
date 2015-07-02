#include "qsgdecbinarywatch.h"
#include <QColor>

QSGDecBinaryWatch::QSGDecBinaryWatch():
    QSGSimpleRectNode()
{
    setColor(QColor(0,0,0,0));
    for (quint8 i = 0; i< 24; ++i)
    {
        appendChildNode(new QSGSimpleRectNode());
    }
}

void QSGDecBinaryWatch::setRect(const QRectF &rect)
{
    qreal he(4*rect.height()/19);
    qreal we(4*rect.width()/29);
    qreal hg(rect.height()/19);
    qreal wg(rect.width()/29);
    qreal top = rect.top();
    qreal left = rect.left();
    QSGSimpleRectNode* node;

    quint8 counter = 0;
    for (quint8 i = 0; i < 6; ++i)
    {
        for (quint8 j = 0; j < 4; ++j)
        {
            node = static_cast<QSGSimpleRectNode*>(childAtIndex(counter));
            node->setRect(left + ( (5 - i) * (we + wg)), top + ((3 - j) * (he + hg)), we, he);
            ++counter;
        }
    }

    QSGSimpleRectNode::setRect(rect);
}

