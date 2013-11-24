#pragma once
#include <iostream>
#include <list>

#include "UMLPort.h"
#include "umlitem.h"
#include "UMLTextItem.h"
class UseCaseItem :
	public UMLItem
{
	//Q_OBJECT
public:
	UseCaseItem(void);
	UseCaseItem(qreal wid,qreal hgt);
	~UseCaseItem(void);
	virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
	virtual QPainterPath shape()const;
	void setName(QString text,int size);
protected:
	virtual void mousePressEvent(QGraphicsSceneMouseEvent *event);
    virtual void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
    virtual void hoverEnterEvent(QGraphicsSceneHoverEvent *event);
    virtual void hoverMoveEvent(QGraphicsSceneHoverEvent *event);
    virtual void hoverLeaveEvent(QGraphicsSceneHoverEvent *event);
private:
	void _addPorts(QPainterPath& path);
	UMLTextItem * _name;
};

