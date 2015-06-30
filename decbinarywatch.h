#ifndef DECBINARYWATCH_H
#define DECBINARYWATCH_H

#include <QQuickItem>
#include <QSGNode>
#include <QColor>
#include <QTime>
#include <QDateTime>

class WatchModel
{
public:
    WatchModel();

    quint32 setTime(const QTime&);
    QTime getTime() const;

    quint32 getSum() const;

private:
    quint32 sum;
    quint8 hh;
    quint8 hl;
    quint8 mh;
    quint8 ml;
    quint8 sh;
    quint8 sl;
};

class DecBinaryWatch : public QQuickItem
{
    Q_OBJECT
    Q_PROPERTY(QTime time READ time WRITE setTime NOTIFY timeChanged)
    Q_PROPERTY(QColor onColor READ onColor WRITE setOnColor)
    Q_PROPERTY(QColor offColor READ offColor WRITE setOffColor)

public:
    DecBinaryWatch(QQuickItem *parent = 0);

    QTime time() const;
    void setTime(const QTime& time);

    QColor onColor() const;
    void setOnColor(const QColor& color);

    QColor offColor() const;
    void setOffColor(const QColor& color);

    QSGNode* updatePaintNode(QSGNode *, UpdatePaintNodeData *);

signals:
    void timeChanged();

private:
    WatchModel m_time;

    QColor on_color;
    QColor off_color;

    bool invalidColor;

    quint32 map;
};

#endif // DECBINARYWATCH_H

