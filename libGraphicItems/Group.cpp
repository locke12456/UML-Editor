#include "Group.h"

using namespace std::placeholders; 
Group::Group(void) : UMLItem() , _currentGroup(nullptr) , _group()
{
	setCalc(this);
}


Group::~Group(void)
{
	std::list< std::list<UMLItem*> *>::const_iterator it = _group.begin();
	for(;it!=_group.end();it++){
		std::list<UMLItem*> * item = *it;
		delete item;
	}
}

void Group::buildGroup()
{
	_currentGroup = new std::list<UMLItem *>();
	_group.push_front(_currentGroup);
}

void Group::releaseGroup()
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

void Group::addMember(UMLItem * item)
{
	if(_currentGroup != nullptr)
	{
		//if(!_isMemberExist(item))
		//{
			_addMmeber(item);
		//}
	}
}
std::list<UMLItem*> * Group::getGroup(){
	return _currentGroup;
}
bool Group::IsInGroup(UMLItem * item)
{
	return _isMemberExist(item);
}
void Group::releaseAll()
{
	std::for_each(_currentGroup->begin(),_currentGroup->end(),std::bind(&Group::_release,this,_1));
}
void Group::groupAll()
{
	std::for_each(_currentGroup->begin(),_currentGroup->end(),std::bind(&Group::_set_group,this,_1));
}
bool Group::hasMemberSelected()
{
	if(_currentGroup == nullptr) return false;
	std::list<UMLItem*>::const_iterator it = _currentGroup->begin();
	for(;it != _currentGroup->end();it++){
		UMLItem* item = *it;
		if(item->getState() == ItemState::Selected)return true;
	}
	return false;
}
void Group::setName(QString text,int size){
}
QPainterPath Group::shape()const{   
	QPainterPath path;

	return path;  
} 
void Group::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){   
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
void Group::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
	UMLItem::mousePressEvent(event);
}
void Group::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
	UMLItem::mouseMoveEvent(event);
	if(_state != ItemState::Selected) return;
	_center = event->scenePos();

}
void Group::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
	UMLItem::mouseReleaseEvent(event);
}

void Group::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
	UMLItem::hoverEnterEvent(event);
}

void Group::hoverMoveEvent(QGraphicsSceneHoverEvent *event)
{
	UMLItem::hoverMoveEvent(event);
}

void Group::hoverLeaveEvent(QGraphicsSceneHoverEvent *event)
{
	UMLItem::hoverLeaveEvent(event);
}
bool Group::_isMemberExist(UMLItem* item)
{
	std::list<UMLItem*>::const_iterator it = std::find(_currentGroup->begin(),_currentGroup->end(),item);
	return it != _currentGroup->end();
}
void Group::_addMmeber(UMLItem* item)
{
	double min_x = FLT_MAX,min_y = FLT_MAX;
	double max_x = 0,max_y = 0;
	std::list<UMLItem*>::const_iterator it = _currentGroup->begin();
	for(;it!=_currentGroup->end();it++){
		UMLItem* item = *it;
		min_x = min(min_x,item->pos().x());		min_y = min(min_y,item->pos().y());
		max_x = max(max_x,item->pos().x());		max_y = max(max_y,item->pos().y());
	}
	setSize(QSize(UMLPort::Distence(QPoint(min_x,0),QPoint(max_x,0)),UMLPort::Distence(QPoint(0,min_y),QPoint(0,max_y))));
	item->JoinToGroup();
	_currentGroup->push_back(item);
}
void Group::_updatePos(UMLItem*item)
{
	QPointF pos = item->scenePos() - _center;
	item->setPos(item->scenePos() + pos);
}
void Group::_updateItems(UMLItem*item){
	//_updatePos(item,pos);
}
void Group::_release(UMLItem* item)
{
	item->LeaveGroup();
}
void Group::_set_group(UMLItem* item)
{
	item->JoinToGroup();
}