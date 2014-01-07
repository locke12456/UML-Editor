#include "UMLLine.h"
#include "UMLScene.h"
UMLLine::UMLLine(void) : _point1(nullptr) , _point2(nullptr) ,  
	_state(ItemState::Normal)
{
	setZValue(-1000);
	setAcceptDrops(true);
	setFlags(ItemIsSelectable);
	setAcceptedMouseButtons(Qt::MouseButtons(Qt::MouseButton::LeftButton));
	setAcceptHoverEvents(true);
}

UMLLine::UMLLine(Port* p1,Port* p2) :  _point1(p1) , _point2(p2) ,
	_state(ItemState::Normal) 
{   
	setZValue(0);
	setAcceptDrops(true);
	setFlags(ItemIsSelectable);
	setAcceptedMouseButtons(Qt::MouseButtons(Qt::MouseButton::LeftButton));
	setAcceptHoverEvents(true);
}  

QRectF UMLLine::boundingRect()const{  
	//if(_point1 == nullptr || _point2 == nullptr)return;
	QPointF point1 = _point1->mapToScene(); 
	QPointF point2 = _point2->mapToScene(); 
	QPointF point =	point1.x()>point2.x() && point1.y()<point2.y() ? QPoint(point2.x() , point1.y()) :
					point1.x()<point2.x() && point1.y()>point2.y() ? QPoint(point1.x() , point2.y()) : QPointMin(point1,point2);
	return QRectF( point.x() , point.y() ,abs((point1-point2).x()) , abs((point1-point2).y()) );
}  

QPainterPath UMLLine::shape()const{   
	QPainterPath path;    
	return path;  
} 
void UMLLine::findInRange(std::list<UMLItem*> ){

}
QLineF UMLLine::getLine()
{
	return QLineF(_point1->mapToScene(),_point2->mapToScene());
}

TargetPosition UMLLine::getTargetPosition()
{
	double x = (_point2->mapToScene().x() - _point1->mapToScene().x());
	double y = (_point2->mapToScene().y() - _point1->mapToScene().y());
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

void UMLLine::setCurrentPoint(Port* point)
{
	_point1 = point;
}

void UMLLine::setTargetPoint(Port* point)
{
	_point2 = point;
}


QRectF UMLLine::_addPot(QPoint pot){
	return QRectF(pot.x()-1,pot.y()-1,2,2);
}

void UMLLine::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
	
	UMLScene *_parent = UMLScene::GetScene(); 
	if(_parent != nullptr && _parent->getState()->getModeState() != SelectItemMode)return;
	_state = ItemState::Selected;
	update();
}

void UMLLine::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
	UMLScene *_parent = UMLScene::GetScene(); 
	if(_parent != nullptr && _parent->getState()->getModeState() != SelectItemMode)return;
	_state = ItemState::Selected;
	update();
}

void UMLLine::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
	UMLScene *_parent = UMLScene::GetScene(); 
	if(_parent != nullptr && _parent->getState()->getModeState() != SelectItemMode)return;
	_state = ItemState::Normal;
	update();
}

void UMLLine::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
	UMLScene *_parent = UMLScene::GetScene(); 
	if(_parent != nullptr && _parent->getState()->getModeState() != SelectItemMode)return;
	if(_state == ItemState::Selected)return;
	_state = ItemState::Hover;
	update();
}

void UMLLine::hoverMoveEvent(QGraphicsSceneHoverEvent *event)
{
	UMLScene *_parent = UMLScene::GetScene(); 
	if(_parent != nullptr && _parent->getState()->getModeState() != SelectItemMode)return;
	if(_state == ItemState::Selected)return;
	_state = ItemState::Hover;
	update();
}

void UMLLine::hoverLeaveEvent(QGraphicsSceneHoverEvent *event)
{
	UMLScene *_parent = UMLScene::GetScene(); 
	if(_parent != nullptr && _parent->getState()->getModeState() != SelectItemMode)return;
	if(_state == ItemState::Selected)return;
	_state = ItemState::Normal;
	update();
}
