#ifndef DECBINARYWATCH_H
#define DECBINARYWATCH_H

#include <QQuickItem>
#include <QSGNode>
#include <QColor>
#include <QTime>
#include <QDateTime>

class DecBinaryWatch : public QQuickItem
{
    Q_OBJECT
    Q_PROPERTY(QTime time READ time WRITE setTime NOTIFY timeChanged)

public:
    DecBinaryWatch(QQuickItem *parent = 0);

    QTime time() const;
    void setTime(const QTime& time);

    QSGNode* updatePaintNode(QSGNode *, UpdatePaintNodeData *);

signals:
    void timeChanged();

private:
    QTime m_time;

    QColor m_full;
    QColor m_empty;
};

#endif // DECBINARYWATCH_H

