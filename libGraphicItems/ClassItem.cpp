#include "ClassItem.h"


ClassItem::ClassItem(void) : UMLItem() ,
	_name(new UMLTextItem)
{
	setCalc(this);
	//_initPorts(_rect());

}

ClassItem::ClassItem(qreal wid,qreal hgt) : UMLItem(wid,hgt),
	_name(new UMLTextItem) , _variable(std::list<UMLTextItem *>()) , _function(std::list<UMLTextItem *>()) 
{
	setCalc(this);
	//_initPorts(_rect());
	_addPort(QPoint(0,-hgt/2));
	_addPort(QPoint(0, hgt/2));
	_addPort(QPoint(-wid/2,0));
	_addPort(QPoint(wid/2,0));
}

ClassItem::~ClassItem(void)
{
	delete _name;
}
void ClassItem::setName(QString text,int size){
	_name->setText(text.toStdString());
	_name->setFont(DEFAULT_FONT,size);
}
void ClassItem::setPos(QPointF p){
	UMLItem::setPos(p);
	if(_state != ItemState::Selected)return;
}
QPainterPath ClassItem::shape(){   
	QPainterPath path = UMLItem::shape();  
	_name->setPosition(_center.x(),_rect().y()+17);
	path.moveTo(_rect().x(),_rect().y()+20);
	path.lineTo(_rect().x()+_rect().width(),_rect().y()+20);
	path.moveTo(_rect().x(),_rect().y()+20+(_rect().height()-20)/2);
	path.lineTo(_rect().x()+_rect().width(),_rect().y()+20+(_rect().height()-20)/2);
	path.addPath(_name->getPath());
	if(IsPortOpen())
		_addPorts(path);
	return path;  
} 
void ClassItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){   
	if(IsInGroup())return;
	Q_UNUSED(widget);   
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
void ClassItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
	//if(IsInGroup())return;
	UMLItem::mousePressEvent(event);
}
void ClassItem::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{

	UMLItem::mouseMoveEvent(event);
	if(_state != ItemState::Selected)return;
	if(IsInGroup()){
		getParent()->moveTo(event->scenePos()-pos());
	}else
		setPos(event->scenePos());
}
void ClassItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
	//if(IsInGroup())return;
	UMLItem::mouseReleaseEvent(event);
}

void ClassItem::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
	//if(IsInGroup())return;
	UMLItem::hoverEnterEvent(event);
}

void ClassItem::hoverMoveEvent(QGraphicsSceneHoverEvent *event)
{
	//if(IsInGroup())return;
	UMLItem::hoverMoveEvent(event);
}

void ClassItem::hoverLeaveEvent(QGraphicsSceneHoverEvent *event)
{
	//if(IsInGroup())return;
	UMLItem::hoverLeaveEvent(event);
}
void ClassItem::_addPorts(QPainterPath& path){
	for(int i = 0;i < length();i++){
		QRectF rect = _getPort(getPotByIndex(i));
		path.addRect(QRectF(_center.x()+rect.x(),_center.y()+rect.y(),rect.width(),rect.height()));
	}
}