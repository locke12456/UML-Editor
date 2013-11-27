#include "UMLItem.h"

UMLItem::UMLItem(void) : _size() ,
	_state(ItemState::Normal) ,_in_group(false)
{
	setZValue(-1000);
	setAcceptDrops(true);
	setFlags(ItemIsSelectable);
	setAcceptedMouseButtons(Qt::MouseButtons(Qt::MouseButton::LeftButton));
	setAcceptHoverEvents(true);
}

UMLItem::UMLItem(qreal wid,qreal hgt) : _state(ItemState::Normal)
	,_in_group(false) , _size(wid,hgt)
{    
	setZValue(-1000);
	setAcceptDrops(true);
	setFlags(ItemIsSelectable);
	setAcceptedMouseButtons(Qt::MouseButtons(Qt::MouseButton::LeftButton));
	setAcceptHoverEvents(true);
}  

QRectF UMLItem::boundingRect()const{   
	return QRectF( -_size.width()/2-1 , -_size.height()/2-1 , _size.width()+2 , _size.height()+2 );
}  

void UMLItem::setSize(QSizeF size)
{
	_size = size;
}

QPainterPath UMLItem::shape(){   
	QPainterPath path;

	if(IsInGroup())_center = pos();
	else _center = QPointF(0,0);
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

void UMLItem::setState(ItemState state)
{
	_state = state;
	update();
}
ItemState UMLItem::getState()
{
	return _state;
}
bool UMLItem::IsInGroup()
{
	return _in_group;
}
void UMLItem::JoinToGroup()
{
	_in_group =true;
}

void UMLItem::LeaveGroup()
{
	_in_group =false;
}

QRectF UMLItem::_rect()const{
	return QRectF(_center.x()+(-_size.width()/2),_center.y()+(-_size.height()/2),_size.width(),_size.height());
}

void UMLItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
	if(_parent != nullptr && _parent->getState() != UMLAddToScene::Select)return;
	//if(_parent->IsItemSelect())return;
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
	_parent->setSelected((void*)this);
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