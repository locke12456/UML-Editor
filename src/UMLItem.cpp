#include "UMLItem.h"
#include "UMLScene.h"
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

//void UMLItem::setParent(UMLScene * parent)
//{
//	_parent = parent;
//}
//
//UMLScene * UMLItem::getParent()
//{
//	return _parent;
//}

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
	_in_group = true;
}

void UMLItem::LeaveGroup()
{
	_in_group = false;
}

Port * UMLItem::FindPoint(QPointF point){
	return _ports.FindPonit(point);
}

QRectF UMLItem::_rect()const{
	return QRectF(_center.x()+(-_size.width()/2),_center.y()+(-_size.height()/2),_size.width(),_size.height());
}

void UMLItem::_addPortToPath(QPainterPath& path){
	for(int i = 0;i < _ports.length();i++){
		QRectF rect = _ports.GetPort(i)->getRect();
		path.addRect(QRectF(_center.x()+rect.x(),_center.y()+rect.y(),rect.width(),rect.height()));
	}
}

void UMLItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
	
	UMLScene *_parent = UMLScene::GetScene(); 
	if(_parent != nullptr && _parent->getState()->getModeState() != SelectItemMode)return;
	//if(_parent->IsItemSelect())return;
	_parent->getState()->setSelected(this);
	_state = ItemState::Selected;
	update();
}

void UMLItem::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
	
	UMLScene *_parent = UMLScene::GetScene(); 
	if(_parent != nullptr && _parent->getState()->getModeState() != SelectItemMode)return;
	_state = ItemState::Selected;
	update();
}

void UMLItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
	
	UMLScene *_parent = UMLScene::GetScene(); 
	if(_parent != nullptr && _parent->getState()->getModeState() != SelectItemMode)return;
	((UMLItem*)_parent->getState()->getSelected())->setState(ItemState::Normal);
	_parent->getState()->setSelected((void*)this);
	_state = ItemState::Selected;
	update();
}

void UMLItem::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
	
	UMLScene *_parent = UMLScene::GetScene(); 
	if(_parent != nullptr && _parent->getState()->getModeState() != SelectItemMode)return;
	if(_state == ItemState::Selected)return;
	_state = ItemState::Hover;
	update();
}

void UMLItem::hoverMoveEvent(QGraphicsSceneHoverEvent *event)
{
	
	UMLScene *_parent = UMLScene::GetScene(); 
	if(_parent != nullptr && _parent->getState()->getModeState() != SelectItemMode)return;
	if(_state == ItemState::Selected)return;
	_state = ItemState::Hover;
	update();
}

void UMLItem::hoverLeaveEvent(QGraphicsSceneHoverEvent *event)
{
	UMLScene *_parent = UMLScene::GetScene(); 
	if(_parent != nullptr && _parent->getState()->getModeState() != SelectItemMode)return;
	if(_state == ItemState::Selected)return;
	_state = ItemState::Normal;
	update();
}