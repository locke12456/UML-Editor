#pragma once
#include <QTimer>
#include <QPainter>
#include <QRectF>
#include <QPainterPath>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsSceneHoverEvent>
#include <QCursor>
#include <QGraphicsItem>
#include <QPainter>
#include <QStyleOptionGraphicsItem>
#include <QStyle>
#include <QGraphicsScene>
#include <UMLBase.h>
#include <ClassItem.h>


class UMLScene :
	public QGraphicsScene , public UMLBase
{
public:
	UMLScene(void);
	~UMLScene(void);
	void addClass();

protected:
	virtual void mousePressEvent(QGraphicsSceneMouseEvent *event);
    virtual void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
private:

	std::list<ClassItem*> _class;
	void _addToScene(QPointF);
	ClassItem * _addClass(QPointF);
	

};

