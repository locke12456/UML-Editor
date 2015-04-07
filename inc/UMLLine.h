#pragma once
#include <QDebug>
#include <UMLItem.h>
#define QPointMin(a,b) ((a.x()<b.x()||a.y()<b.y())?a:b) 
enum TargetPosition
{
	Center,Up,Down,Left,Right
};
class UMLLine :
	public QAbstractGraphicsShapeItem 
{
	//Q_OBJECT
public:
	UMLLine(void);
	UMLLine(Port* p1,Port* p2);
	QRectF boundingRect()const;   
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);   
    virtual QPainterPath shape()const; 
	void setCurrentPoint(Port *);
	void setTargetPoint(Port *);
	TargetPosition getTargetPosition();
	UMLState * getParent();
	QLineF getLine();
	virtual void findInRange(std::list<UMLItem*>);
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
    Port* _point1;  
    Port* _point2; 
	int _parent_index;
	int _target_index;
};

