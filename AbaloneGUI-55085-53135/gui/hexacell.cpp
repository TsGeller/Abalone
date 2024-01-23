#include "hexacell.h"
#include "point.h"

#include <QGraphicsSceneMouseEvent>
#include <QPen>
#include <QBrush>
#include <QPainter>
#include <QDebug>
#include <QStyleOptionGraphicsItem>
#include <QWidget>

#include <iostream>
#include <cmath>

HexaCell::HexaCell(double rad,
                   double dx,
                   double dy,
                   unsigned color,
                   std::string pos,
                   QGraphicsItem * parent)
    : QGraphicsPolygonItem(parent),
      _rad{rad}, _dx{dx}, _dy{dy}, _color(color), _pos{pos},
      _mouseover(false), _selected(false), _moved(false)
{
    this->setAcceptHoverEvents(true);

    static const double piOver6 = atan(1) * 4 / 6;

    QPolygonF polygon;
    auto && corners = orbit({dx, dy}, 6, rad, piOver6);
    for (auto & p : corners)
        polygon << QPointF(p.first, p.second);

    setPolygon(polygon);
}

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-parameter"
void HexaCell::paint(QPainter * painter,
                     const QStyleOptionGraphicsItem * option,
                     QWidget * widget)
{
    if (_selected)
    {
        QPen pen(Qt::red, 3);
        painter->setPen(pen);
        painter->setBrush(colorCell());
    }
    else if (_mouseover)
    {
        QPen pen(Qt::green, 3);
        painter->setPen(pen);
        painter->setBrush(colorCell());
    }
    else
    {
        QPen pen(Qt::gray, 1);
        painter->setPen(pen);
        painter->setBrush(colorCell());
    }

    painter->drawPolygon(polygon());
}

QBrush HexaCell::colorCell()
{
    QBrush brush;
    if (_color == 1)
    {
        brush.setColor(Qt::white);
        brush.setStyle(Qt::SolidPattern);
    }
    else if (_color == 2)
    {
        brush.setColor(Qt::black);
        brush.setStyle(Qt::SolidPattern);
    }
    else
    {
        brush.setColor(Qt::darkGray);
        brush.setStyle(Qt::SolidPattern);
    }
    return brush;
}

void HexaCell::hoverEnterEvent(QGraphicsSceneHoverEvent * event)
{
    _mouseover = true;
    update();
}

void HexaCell::hoverLeaveEvent(QGraphicsSceneHoverEvent * event)
{
    _mouseover = false;
    update();
}

void HexaCell::mousePressEvent(QGraphicsSceneMouseEvent * event)
{
    event->accept();
    qDebug() << "mouse event press signal !";
    emit sendValue(_pos);

    _moved = false;
    _selected = !_selected; //I'd like to put this in "released"
    update();

    //relaunches the event in order to allow dragging
    QGraphicsItem::mousePressEvent(event);
}

void HexaCell::mouseReleaseEvent(QGraphicsSceneMouseEvent * event)
{
    //why isn't this ever fired ?
}

void HexaCell::mouseMoveEvent(QGraphicsSceneMouseEvent * event)
{
    _moved = true;
}

void HexaCell::wheelEvent(QGraphicsSceneWheelEvent * event)
{
    //write stuff here
    //rad +/-= 10 ?

    QGraphicsItem::wheelEvent(event);
}

void HexaCell::unselect()
{
    _selected = false;
    update();
}



#pragma GCC diagnostic pop

