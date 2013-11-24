#include "ClassItem.h"


ClassItem::ClassItem(void) : UMLItem() ,
	_name(new UMLTextItem)
{
	setCalc(this);
	_initPorts(_rect());
}

ClassItem::ClassItem(qreal wid,qreal hgt) : UMLItem(wid,hgt),
	_name(new UMLTextItem) , _variable(std::list<UMLTextItem *>()) , _function(std::list<UMLTextItem *>()) 
{
	setCalc(this);
	_initPorts(_rect());
}

ClassItem::~ClassItem(void)
{
	delete _name;
}
void ClassItem::setName(QString text,int size){
	_name->setText(text.toStdString());
	_name->setFont(DEFAULT_FONT,size);
}
QPainterPath ClassItem::shape()const{   
	QPainterPath path = UMLItem::shape();  
	_name->setPosition(_rect().x()+4,_rect().y()+17);
	path.moveTo(_rect().x(),_rect().y()+20);
	path.lineTo(_rect().x()+_rect().width(),_rect().y()+20);
	path.moveTo(_rect().x(),_rect().y()+20+(_rect().height()-20)/2);
	path.lineTo(_rect().x()+_rect().width(),_rect().y()+20+(_rect().height()-20)/2);
	path.addPath(_name->getPath());
	return path;  
} 
void ClassItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){   
	Q_UNUSED(widget);   
	QPainterPath temp;
	if(getParent()->IsAddLineItem())
		_addPorts(temp);
	if(_state & ItemState::Selected){    
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
void ClassItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
	UMLItem::mousePressEvent(event);
}
void ClassItem::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
	UMLItem::mouseMoveEvent(event);
	if(_state != ItemState::Selected)return;
	setPos(event->scenePos().x(),event->scenePos().y());
	getParent()->update_lines();
}
void ClassItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
	UMLItem::mouseReleaseEvent(event);
}

void ClassItem::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
	UMLItem::hoverEnterEvent(event);
}

void ClassItem::hoverMoveEvent(QGraphicsSceneHoverEvent *event)
{
	UMLItem::hoverMoveEvent(event);
}

void ClassItem::hoverLeaveEvent(QGraphicsSceneHoverEvent *event)
{
	UMLItem::hoverLeaveEvent(event);
}
void ClassItem::_addPorts(QPainterPath& path){
	for(int i = 0;i < length();i++)
		path.addRect(_getPort(getPotByIndex(i)));
}