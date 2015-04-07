#pragma once
#include <iostream>
#include <functional>
#include <list>
#include <QDebug>
#include <umlline.h>
#include <UMLItem.h>
#include <PortFactory.h>
class ItemSelect :
	public UMLLine
{
public:
	ItemSelect(void);
	ItemSelect(Port* p1,Port* p2);
	~ItemSelect(void);
	virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
	QPainterPath shape();
	void findInRange(std::list<UMLItem*>);
	void releaseAll(std::list<UMLItem*>);
	void selectAll(std::list<UMLItem*>);
	std::list<UMLItem *> getSelectedItems(std::list<UMLItem*>);
protected:
	virtual void mousePressEvent(QGraphicsSceneMouseEvent *event);
    virtual void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
private:
	void _inRange(UMLItem*);
	void _release(UMLItem*);
	void _select(UMLItem*);
	void _getSelected(UMLItem*);
	std::list<UMLItem*> _list;
};
