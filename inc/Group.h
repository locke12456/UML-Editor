#pragma once
#include <iostream>
#include <list>
#include <functional>
#include <algorithm>
#include "PortFactory.h"
#include "umlitem.h"
#include "UMLTextItem.h"
class UMLGroup :
	public UMLItem
{
	//Q_OBJECT
public:
	UMLGroup(void);
	~UMLGroup(void);
	virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
	virtual QPainterPath shape()const;
	std::list<UMLItem*> * getGroup();

	bool IsInGroup(UMLItem * );
	bool hasMemberSelected();
	void buildGroup();
	void releaseGroup();
	void moveTo(QPointF point);
	void addMember(UMLItem*);
	void addToGrop(UMLItem*);
	void groupAll();
	void releaseAll();

protected:
	virtual void mousePressEvent(QGraphicsSceneMouseEvent *event);
    virtual void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
    virtual void hoverEnterEvent(QGraphicsSceneHoverEvent *event);
    virtual void hoverMoveEvent(QGraphicsSceneHoverEvent *event);
    virtual void hoverLeaveEvent(QGraphicsSceneHoverEvent *event);

private:
	bool _isMemberExist(UMLItem*);
	void _addMmeber(UMLItem*);
	void _updatePos(UMLItem*);
	void _updateItems(UMLItem*);
	void _release(UMLItem*);
	void _set_group(UMLItem*);
	void setName(QString text,int size);
	std::list<std::list<UMLItem*> *> _group;
	std::list<UMLItem*> * _currentGroup;
	QPointF _center;
};

