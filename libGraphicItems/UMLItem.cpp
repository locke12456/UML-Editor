#include "UMLItem.h"

UMLItem::UMLItem(void) : _width() , _height() ,
	_state(ItemState::Normal)
{
	setZValue(0);
	setAcceptDrops(true);
	setFlags(ItemIsSelectable);
	setAcceptedMouseButtons(Qt::MouseButtons(Qt::MouseButton::LeftButton));
	setAcceptHoverEvents(true);
}

UMLItem::UMLItem(qreal wid,qreal hgt) : _state(ItemState::Normal) {   
	_width=wid;_height=hgt;  
	setZValue(0);
	setAcceptDrops(true);
	setFlags(ItemIsSelectable);
	setAcceptedMouseButtons(Qt::MouseButtons(Qt::MouseButton::LeftButton));
	setAcceptHoverEvents(true);
}  

QRectF UMLItem::boundingRect()const{   
	return QRectF( -_width/2-1 , -_height/2-1 , _width+2 , _height+2 );
}  

QPainterPath UMLItem::shape()const{   
	QPainterPath path;   
	path.addRect(_rect());     
	return path;  
} 

void UMLItem::setParent(UMLBase * parent)
{
	_parent = parent;
}

UMLBase * UMLItem::getParent()
{
	return _parent;
}

QRectF UMLItem::_rect()const{
	return QRectF(-_width/2,-_height/2,_width,_height);
}

void UMLItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
	if(_parent != nullptr && _parent->getState() != UMLAddToScene::Select)return;
	_state = ItemState::Selected;
	update();
}

void UMLItem::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
	if(_parent != nullptr && _parent->getState() != UMLAddToScene::Select)return;
	_state = ItemState::Selected;
	update();
}

void UMLItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
	if(_parent != nullptr && _parent->getState() != UMLAddToScene::Select)return;
	_state = ItemState::Normal;
	update();
}

void UMLItem::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
	if(_parent != nullptr && _parent->getState() != UMLAddToScene::Select)return;
	if(_state == ItemState::Selected)return;
	_state = ItemState::Hover;
	update();
}

void UMLItem::hoverMoveEvent(QGraphicsSceneHoverEvent *event)
{
	if(_parent != nullptr && _parent->getState() != UMLAddToScene::Select)return;
	if(_state == ItemState::Selected)return;
	_state = ItemState::Hover;
	update();
}

void UMLItem::hoverLeaveEvent(QGraphicsSceneHoverEvent *event)
{
	if(_parent != nullptr && _parent->getState() != UMLAddToScene::Select)return;
	if(_state == ItemState::Selected)return;
	_state = ItemState::Normal;
	update();
}