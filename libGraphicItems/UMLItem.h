#pragma once

#include <QTimer>
#include <QPainter>
#include <QRectF>
#include <QPainterPath>
#include <QGraphicsSceneHoverEvent>
#include <QGraphicsSceneMouseEvent>
#include <QCursor>
#include <QGraphicsItem>
#include <QPainter>
#include <QStyleOptionGraphicsItem>
#include <QStyle>
#include <UMLBase.h>
#include <UMLPort.h>
enum ItemState{
	Normal,Selected,Hover
};
class UMLItem :
	public QGraphicsItem ,  public UMLPort 
{
	//Q_OBJECT
public:
	UMLItem(void);
	UMLItem(qreal wid,qreal hgt);
	QRectF boundingRect()const;   
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) = 0;   
    virtual QPainterPath shape();
	virtual void setName(QString ,int ) = 0;
	void setParent(UMLBase * parent);
	UMLBase * getParent();

	void setState(ItemState);
	ItemState getState();

	bool IsInGroup();
	void JoinToGroup();
	void LeaveGroup();
	void setSize(QSizeF);
	
protected :
	QRectF _rect()const;
	QPointF _center;
    virtual void mousePressEvent(QGraphicsSceneMouseEvent *event);
    virtual void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
    virtual void hoverEnterEvent(QGraphicsSceneHoverEvent *event);
    virtual void hoverMoveEvent(QGraphicsSceneHoverEvent *event);
    virtual void hoverLeaveEvent(QGraphicsSceneHoverEvent *event);
	ItemState _state;
private:   
	bool _in_group;
	
	UMLBase * _parent;
    QSizeF _size;  
};

