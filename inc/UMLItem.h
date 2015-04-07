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
#include <UMLState.h>
#include <PortFactory.h>
//#include "UMLScene.h"
enum ItemState{
	Normal,Selected,Hover
};

class UMLItem :
	public QAbstractGraphicsShapeItem
{
	//Q_OBJECT
public:
	UMLItem(void);
	UMLItem(qreal wid,qreal hgt);

	QRectF boundingRect()const;   
	virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) = 0;   
	virtual QPainterPath shape();

	virtual void setName(QString ,int ) = 0;
	//void setParent(UMLScene * parent);
	//UMLScene * getParent();
	void setState(ItemState);
	ItemState getState();

	bool IsInGroup();
	void JoinToGroup();
	void LeaveGroup();
	void setSize(QSizeF);
	Port * FindPoint(QPointF point);
protected :
	PortFactory _ports;
	void _addPortToPath(QPainterPath& path);
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
	//UMLScene * _parent;
	QSizeF _size;  
};

