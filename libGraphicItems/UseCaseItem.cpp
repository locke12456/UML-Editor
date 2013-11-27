#include "UseCaseItem.h"


UseCaseItem::UseCaseItem(void) : UMLItem() ,
	_name(new UMLTextItem)
{
	setCalc(this);
}

UseCaseItem::UseCaseItem(qreal wid,qreal hgt) : UMLItem(wid,hgt),
	_name(new UMLTextItem) 
{
	setCalc(this);
	_addPort(QPoint(0,-hgt/2));
	_addPort(QPoint(0, hgt/2));
	_addPort(QPoint(-wid/2,0));
	_addPort(QPoint(wid/2,0));
}

UseCaseItem::~UseCaseItem(void)
{
	delete _name;
}
void UseCaseItem::setName(QString text,int size){
	_name->setText(text.toStdString());
	_name->setFont(DEFAULT_FONT,size);
}
QPainterPath UseCaseItem::shape(){   
	QPainterPath path;
	_center = QPoint(0,0);
	if(IsInGroup())_center = pos();
	path.addEllipse(_rect());    
	_name->setPosition(_center.x(),_center.y()+8);
	path.addPath(_name->getPath());
	if(IsPortOpen())
		_addPorts(path);
	return path;  
} 
void UseCaseItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){   
	Q_UNUSED(widget);   
	if(IsInGroup())return;
	QPainterPath temp;

	if(_state & ItemState::Selected || getParent()->getSelected() == this){    
		painter->setPen(QPen(Qt::red,2,Qt::SolidLine));  
	}
	if(_state & ItemState::Hover){    
		painter->setPen(QPen(Qt::red,1,Qt::SolidLine));   
	}
	QPainterPath path = shape();
	path.addPath(temp);
	painter->fillPath(path,Qt::white);
	painter->drawPath(path);
} 
void UseCaseItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
	UMLItem::mousePressEvent(event);
}
void UseCaseItem::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
	UMLItem::mouseMoveEvent(event);
	if(_state != ItemState::Selected)return;
	if(IsInGroup()){
		getParent()->moveTo(event->scenePos()-pos());
	}else
		setPos(event->scenePos());
}
void UseCaseItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
	UMLItem::mouseReleaseEvent(event);
}

void UseCaseItem::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
	UMLItem::hoverEnterEvent(event);
}

void UseCaseItem::hoverMoveEvent(QGraphicsSceneHoverEvent *event)
{
	UMLItem::hoverMoveEvent(event);
}

void UseCaseItem::hoverLeaveEvent(QGraphicsSceneHoverEvent *event)
{
	UMLItem::hoverLeaveEvent(event);
}
void UseCaseItem::_addPorts(QPainterPath& path){
	for(int i = 0;i < length();i++){
		QRectF rect = _getPort(getPotByIndex(i));
		path.addRect(QRectF(_center.x()+rect.x(),_center.y()+rect.y(),rect.width(),rect.height()));
	}
}