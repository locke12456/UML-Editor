#include "Group.h"

using namespace std::placeholders; 
UMLGroup::UMLGroup(void) : UMLItem() , _currentGroup(nullptr) , _group()
{
}


UMLGroup::~UMLGroup(void)
{
	std::list< std::list<UMLItem*> *>::const_iterator it = _group.begin();
	for(;it!=_group.end();it++){
		std::list<UMLItem*> * item = *it;
		delete item;
	}
}

void UMLGroup::buildGroup()
{
	_currentGroup = new std::list<UMLItem *>();
	_group.push_front(_currentGroup);
}

void UMLGroup::releaseGroup()
{
	releaseAll();
	delete _currentGroup;
	if(_group.size() > 1){
		_group.pop_front();
		_currentGroup = *_group.begin();
		groupAll();
	}else {
		_group.pop_front();
		_currentGroup = nullptr;
	}
}

void UMLGroup::addMember(UMLItem * item)
{
	if(_currentGroup != nullptr)
	{
		//if(!_isMemberExist(item))
		//{
			_addMmeber(item);
		//}
	}
}
std::list<UMLItem*> * UMLGroup::getGroup(){
	return _currentGroup;
}
bool UMLGroup::IsInGroup(UMLItem * item)
{
	return _isMemberExist(item);
}
void UMLGroup::releaseAll()
{
	std::for_each(_currentGroup->begin(),_currentGroup->end(),std::bind(&UMLGroup::_release,this,_1));
}
void UMLGroup::groupAll()
{
	std::for_each(_currentGroup->begin(),_currentGroup->end(),std::bind(&UMLGroup::_set_group,this,_1));
}
bool UMLGroup::hasMemberSelected()
{
	if(_currentGroup == nullptr) return false;
	std::list<UMLItem*>::const_iterator it = _currentGroup->begin();
	for(;it != _currentGroup->end();it++){
		UMLItem* item = *it;
		if(item->getState() == ItemState::Selected)return true;
	}
	return false;
}
void UMLGroup::setName(QString text,int size){
}
QPainterPath UMLGroup::shape()const{   
	QPainterPath path;

	return path;  
} 
void UMLGroup::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){   
	Q_UNUSED(widget);   
	if(_currentGroup == nullptr) return ;
	QPainterPath temp;
	if(hasMemberSelected()){    
		painter->setPen(QPen(Qt::red,2,Qt::SolidLine));  
	}
	if(_state & ItemState::Hover){    
		painter->setPen(QPen(Qt::red,1,Qt::SolidLine));   
	}
	QPainterPath path = shape();
	std::list<UMLItem*>::const_iterator it = _currentGroup->begin();
	for(;it!=_currentGroup->end();it++){
		UMLItem* item = *it;
		path = (item->shape());
		painter->fillPath(path,Qt::white);
		painter->drawPath(path);
	}

} 
void UMLGroup::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
	UMLItem::mousePressEvent(event);
}
void UMLGroup::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
	UMLItem::mouseMoveEvent(event);
	if(_state != ItemState::Selected) return;
	_center = event->scenePos();

}
void UMLGroup::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
	UMLItem::mouseReleaseEvent(event);
}

void UMLGroup::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
	UMLItem::hoverEnterEvent(event);
}

void UMLGroup::hoverMoveEvent(QGraphicsSceneHoverEvent *event)
{
	UMLItem::hoverMoveEvent(event);
}

void UMLGroup::hoverLeaveEvent(QGraphicsSceneHoverEvent *event)
{
	UMLItem::hoverLeaveEvent(event);
}
bool UMLGroup::_isMemberExist(UMLItem* item)
{
	std::list<UMLItem*>::const_iterator it = std::find(_currentGroup->begin(),_currentGroup->end(),item);
	return it != _currentGroup->end();
}
void UMLGroup::_addMmeber(UMLItem* item)
{
	double min_x = FLT_MAX,min_y = FLT_MAX;
	double max_x = 0,max_y = 0;
	std::list<UMLItem*>::const_iterator it = _currentGroup->begin();
	for(;it!=_currentGroup->end();it++){
		UMLItem* item = *it;
		min_x = min(min_x,item->pos().x());		min_y = min(min_y,item->pos().y());
		max_x = max(max_x,item->pos().x());		max_y = max(max_y,item->pos().y());
	}
	setSize(QSize(PortFactory::Distence(QPoint(min_x,0),QPoint(max_x,0)),PortFactory::Distence(QPoint(0,min_y),QPoint(0,max_y))));
	item->JoinToGroup();
	_currentGroup->push_back(item);
}
void UMLGroup::_updatePos(UMLItem*item)
{
	QPointF pos = item->scenePos() - _center;
	item->setPos(item->scenePos() + pos);
}
void UMLGroup::_updateItems(UMLItem*item){
	//_updatePos(item,pos);
}
void UMLGroup::_release(UMLItem* item)
{
	item->LeaveGroup();
}
void UMLGroup::_set_group(UMLItem* item)
{
	item->JoinToGroup();
}