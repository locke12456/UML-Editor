#include "UMLLine.h"

UMLLine::UMLLine(void) : _point1() , _point2() ,
	_target_item(nullptr) , _parent_item(nullptr),
	_state(ItemState::Normal)
{
	setZValue(-1000);
	setAcceptDrops(true);
	setFlags(ItemIsSelectable);
	setAcceptedMouseButtons(Qt::MouseButtons(Qt::MouseButton::LeftButton));
	setAcceptHoverEvents(true);
}

UMLLine::UMLLine(QPoint p1,QPoint p2) :  _point1(p1) , _point2(p2) ,
	_target_item(nullptr) , _parent_item( nullptr ) ,
	_state(ItemState::Normal) 
{   
	setZValue(0);
	setAcceptDrops(true);
	setFlags(ItemIsSelectable);
	setAcceptedMouseButtons(Qt::MouseButtons(Qt::MouseButton::LeftButton));
	setAcceptHoverEvents(true);
}  

QRectF UMLLine::boundingRect()const{  
	
	QPoint point =	_point1.x()>_point2.x() && _point1.y()<_point2.y() ? QPoint(_point2.x() , _point1.y()) :
					_point1.x()<_point2.x() && _point1.y()>_point2.y() ? QPoint(_point1.x() , _point2.y()) : QPointMin(_point1,_point2);
	return QRectF( point.x() , point.y() ,abs((_point1-_point2).x()) , abs((_point1-_point2).y()) );
}  

QPainterPath UMLLine::shape()const{   
	QPainterPath path;    
	return path;  
} 
void UMLLine::findInRange(std::list<UMLItem*> ){

}
QLineF UMLLine::getLine()
{
	if(_parent_item!=nullptr)_point1 = _parent_item->FindPonit(_point1);
	if(_target_item!=nullptr)_point2 = _target_item->FindPonit(_point2);
	return QLineF(mapToScene(_point1),mapToScene(_point2));
}

TargetPosition UMLLine::getTargetPosition()
{
	double x = (_point2.x() - _point1.x());
	double y = (_point2.y() - _point1.y());
	double theta = atan((x / y));
	double angle = abs(theta / 3.14159 * 180);
	if (y > 0){
		if (x > 0){
			angle = angle;
		} else {
			angle = (360 - angle);
		}
	}
	if (y < 0){
		if (x > 0){
			angle = (180 - angle);
		} else {
			angle = (180 + angle);
		}
	}
	if( angle < 45 || angle > 315 ) 
		return TargetPosition::Down;
	if( angle >= 45 && angle < 135 ) 
		return TargetPosition::Right;
	if( angle >= 135 && angle < 225 ) 
		return TargetPosition::Up;
	return TargetPosition::Left;
}

void UMLLine::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){   
	Q_UNUSED(widget);   
	QPainterPath temp;

	if(_state & ItemState::Selected){    
		painter->setPen(QPen(Qt::red,2,Qt::SolidLine));  
	}
	if(_state & ItemState::Hover){    
		painter->setPen(QPen(Qt::red,1,Qt::SolidLine));   
	}
	painter->drawLine(getLine());
} 

void UMLLine::setCurrentPoint(QPoint point)
{
	_point1 = point;
}

void UMLLine::setTargetPoint(QPoint point)
{
	_point2 = point;
}

void UMLLine::setParent(UMLBase * parent)
{
	_parent = parent;
}

void UMLLine::setTargetItem(UMLItem* item,int index)
{
	_target_item = item;
	_target_index = index;
}

void UMLLine::setParentItem(UMLItem* item , int index)
{
	_parent_item = item;
	_parent_index = index;
}

UMLBase * UMLLine::getParent()
{
	return _parent;
}

QRectF UMLLine::_addPot(QPoint pot){
	return QRectF(pot.x()-1,pot.y()-1,2,2);
}

void UMLLine::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
	if(_parent != nullptr && _parent->getState() != UMLAddToScene::Select)return;
	_state = ItemState::Selected;
	update();
}

void UMLLine::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
	if(_parent != nullptr && _parent->getState() != UMLAddToScene::Select)return;
	_state = ItemState::Selected;
	update();
}

void UMLLine::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
	if(_parent != nullptr && _parent->getState() != UMLAddToScene::Select)return;
	_state = ItemState::Normal;
	update();
}

void UMLLine::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
	if(_parent != nullptr && _parent->getState() != UMLAddToScene::Select)return;
	if(_state == ItemState::Selected)return;
	_state = ItemState::Hover;
	update();
}

void UMLLine::hoverMoveEvent(QGraphicsSceneHoverEvent *event)
{
	if(_parent != nullptr && _parent->getState() != UMLAddToScene::Select)return;
	if(_state == ItemState::Selected)return;
	_state = ItemState::Hover;
	update();
}

void UMLLine::hoverLeaveEvent(QGraphicsSceneHoverEvent *event)
{
	if(_parent != nullptr && _parent->getState() != UMLAddToScene::Select)return;
	if(_state == ItemState::Selected)return;
	_state = ItemState::Normal;
	update();
}
