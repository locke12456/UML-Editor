#include "Association.h"

Association::Association(void) : UMLLine()
{
}

Association::Association(Port* p1,Port* p2) : UMLLine(p1,p2)
{
}

Association::~Association(void)
{
}
void Association::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
	UMLLine::mousePressEvent(event);
}
void Association::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
	UMLLine::mouseMoveEvent(event);
	if(_state != ItemState::Selected)return;
	setPos(event->scenePos().x(),event->scenePos().y());
}
void Association::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
	UMLLine::mouseReleaseEvent(event);
}

void Association::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
	UMLLine::hoverEnterEvent(event);
}

void Association::hoverMoveEvent(QGraphicsSceneHoverEvent *event)
{
	UMLLine::hoverMoveEvent(event);
}

void Association::hoverLeaveEvent(QGraphicsSceneHoverEvent *event)
{
	UMLLine::hoverLeaveEvent(event);
}
//void Association::_addPots(QPainterPath& path){
//	//for(int i = 0;i < length();i++)
//	//	path.addRect(_addPot(getPortByIndex(i)));
//}