#include "qsgdecbinarywatch.h"
#include <QColor>
#include <QtMath>

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
    qreal wg(qBound(2.0, qMin(rect.width()/29, rect.height()/19), 10.0));

    qreal hg(wg);

    qreal he((rect.height() - 3 * hg)/4);
    qreal we((rect.width() - 5 * wg)/6);

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

