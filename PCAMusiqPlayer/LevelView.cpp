#include "LevelView.h"

#include <QDebug>
#include <QPointF>
#include <QPainter>
#include <QPainterPath>

#include <ctime>

#include "MathUtil.h"

LevelView::LevelView()
{
    valueLabelWidth = 100.0;
    qDebug() << "Created a LevelView";
    receivedFirstValue = false;
}

void LevelView::setValue(float value)
{
    if(!receivedFirstValue)
    {
        max = value;
        min = value;
        receivedFirstValue = true;
    }
    else
    {
        max = MAX(max, value);
        min = MIN(min, value);
    }

    currentValue = value;
    //qDebug() << "currentValue: " << currentValue;
}

QRectF LevelView::boundingRect() const
{
    return rect;
}

void LevelView::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QRectF plotRect = boundingRect();
    plotRect.setRight(plotRect.right() - valueLabelWidth);
    QRectF labelRect = boundingRect();
    labelRect.setLeft(plotRect.right());

    QPointF middleLeft(plotRect.left(), plotRect.height()/2.0);
    QPointF middleRight(plotRect.right(), plotRect.height()/2.0);


    painter->setPen(QColor(230, 230, 230));
    painter->drawLine(middleLeft, middleRight);

    painter->setPen(QColor(0, 0, 0));
    painter->drawRect(boundingRect());
    painter->drawRect(plotRect);

    painter->drawText(labelRect, QString("%1").arg(currentValue));

    float normalized = (currentValue - min) / (max - min);
    QColor color = QColor(230, 50, 50);
    painter->setPen(color);
    painter->setBrush(QBrush(color));
    painter->drawRect(rect.left(), rect.top() + normalized * rect.height(), rect.width(), rect.height() / 10.0);
}
