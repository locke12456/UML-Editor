#pragma once
#include <QDebug>
#include <UMLItem.h>
enum TargetPosition
{
	Center,Up,Down,Left,Right
};
class UMLLine :
	public QGraphicsLineItem 
{
	//Q_OBJECT
public:
	UMLLine(void);
	UMLLine(QPoint p1,QPoint p2);
	QRectF boundingRect()const;   
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);   
    virtual QPainterPath shape()const;  
	void setParent(UMLBase * parent);
	void setCurrentPoint(QPoint);
	void setTargetPoint(QPoint);
	void setTargetItem(UMLItem *);
	void setParentItem(UMLItem *);
	TargetPosition getTargetPosition();
	UMLBase * getParent();
	QLineF getLine();
protected :
	QRectF _addPot(QPoint);
    virtual void mousePressEvent(QGraphicsSceneMouseEvent *event);
    virtual void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
    virtual void hoverEnterEvent(QGraphicsSceneHoverEvent *event);
    virtual void hoverMoveEvent(QGraphicsSceneHoverEvent *event);
    virtual void hoverLeaveEvent(QGraphicsSceneHoverEvent *event);
	ItemState _state;
private:   
	UMLBase * _parent;
    QPoint _point1;  
    QPoint _point2; 
	UMLItem * _parent_item;
	UMLItem * _target_item;

};

