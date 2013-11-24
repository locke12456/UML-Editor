#pragma once
#include <iostream>
#include <list>
#include <umlline.h>
#include <UMLPort.h>
class Association :
	public UMLLine ,  public UMLPort
{
public:
	Association(void);
	Association(QPoint p1,QPoint p2);
	~Association(void);
protected:
	virtual void mousePressEvent(QGraphicsSceneMouseEvent *event);
    virtual void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

    virtual void hoverEnterEvent(QGraphicsSceneHoverEvent *event);
    virtual void hoverMoveEvent(QGraphicsSceneHoverEvent *event);
    virtual void hoverLeaveEvent(QGraphicsSceneHoverEvent *event);
private:
	void _addPots(QPainterPath& path);
};
