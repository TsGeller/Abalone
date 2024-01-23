#ifndef HEXACELL_H
#define HEXACELL_H

#include <QGraphicsPolygonItem>
#include <QPolygonF>
#include <string>
#include <QPointF>
#include <QObject>

class QPainter;
class QStyleOptionGraphicsItem;
class QWidget;
class QGraphicsSceneHoverEvent;
class QGraphicsSceneMouseEvent;
class QGraphicsSceneWheelEvent;
/**
 * @brief The HexaCell class class of hexacell who create an hexacell
 */
class HexaCell : public QObject, public QGraphicsPolygonItem
{
    Q_OBJECT

  protected:
    double _rad, _dx, _dy;//hexagon radius, coordinate (x,y) of center
    unsigned _color;//color of hexacell
    std::string _pos;// position of hexacell
    bool _mouseover, _selected, _moved;//mouse interaction booleans

  public:
    /**
     * @brief HexaCell conctructor of hexacell
     * @param rad radius
     * @param dx dx
     * @param dy dy
     * @param color color cell
     * @param pos position of cell
     * @param parent parent of cell
     */
    HexaCell(double rad = 100,
             double dx = 0,
             double dy = 0,
             unsigned color = 0,
             std::string pos = "0",
             QGraphicsItem * parent = 0);
    /**
     * @brief paint paint the hexacell
     * @param painter
     * @param option
     * @param widget
     */
    void paint(QPainter * painter,
               const QStyleOptionGraphicsItem * option,
               QWidget * widget);
    /**
     * @brief unselect unselect an hexacell
     */
    void unselect();
    /**
     * @brief coord get the coord of hexacell
     * @param x coord x
     * @param y coord y
     * @return
     */
    inline QPointF coord(double x, double y) const;
    /**
     * @brief setLocation set the location of hexacell
     * @param x param x
     * @param y param y
     */
    inline void setLocation(double x, double y);
    /**
     * @brief getPos get the position of hexacell
     * @return the string position
     */
    inline std::string getPos();
    /**
     * @brief setColor set the color of hexacel
     */
    inline void setColor(unsigned);

  protected:
    /**
     * @brief hoverEnterEvent make event when hexacell is clicked
     * @param event
     */
    void hoverEnterEvent(QGraphicsSceneHoverEvent * event);
    /**
     * @brief hoverLeaveEventmake event when hexacell is clicked 2 times
     * @param event
     */
    void hoverLeaveEvent(QGraphicsSceneHoverEvent * event);
    /**
     * @brief mousePressEvent make event when mouse are clicked
     * @param event
     */
    void mousePressEvent(QGraphicsSceneMouseEvent * event);
    /**
     * @brief mouseReleaseEvent make event when mouse are unclicked
     * @param event
     */
    void mouseReleaseEvent(QGraphicsSceneMouseEvent * event);
    /**
     * @brief mouseMoveEvent
     * @param event
     */
    void mouseMoveEvent(QGraphicsSceneMouseEvent * event);
    /**
     * @brief wheelEvent
     * @param event
     */
    void wheelEvent(QGraphicsSceneWheelEvent * event);

  signals:
    /**
     * @brief sendValuesend the valeu of hexacell
     * @param value value hexacell
     */
    void sendValue(std::string value);

  private:
    /**
     * @brief colorCell color the hexacell
     * @return
     */
    QBrush colorCell();
};
/**
 * @brief HexaCell::getPos get the position of hexacell
 * @return string position
 */
inline std::string HexaCell::getPos()
{
    return _pos;
}
/**
 * @brief HexaCell::setColor set the color of hexacell
 * @param color color cell
 */
inline void HexaCell::setColor(unsigned color)
{
    _color = color;
}
#endif // HEXACELL_H
