#pragma once
#include <UMLLine.h>
#include <UMLItem.h>
#define FLAG_SIZE 7.5
class Generalization : public UMLLine 
{
public:
	Generalization(void);
	Generalization(Port* p1,Port* p2);
	~Generalization(void);
	virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
	QPainterPath shape();
protected:
	virtual void mousePressEvent(QGraphicsSceneMouseEvent *event);
	virtual void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
	virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

	virtual void hoverEnterEvent(QGraphicsSceneHoverEvent *event);
	virtual void hoverMoveEvent(QGraphicsSceneHoverEvent *event);
	virtual void hoverLeaveEvent(QGraphicsSceneHoverEvent *event);
private:
	QPainterPath _getLeftFlag();
	QPainterPath _getRightFlag();

	QPainterPath _getUpFlag();
	QPainterPath _getDownFlag();

	QPainterPath _getLine();
};

