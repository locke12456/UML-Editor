#include "ClassItem.h"
#include "UMLScene.h"

ClassItem::ClassItem(void) : UMLItem() ,
	_name(new UMLTextItem)
{
	//setCalc(this);
	//_initPorts(_rect());

}

ClassItem::ClassItem(qreal wid,qreal hgt) : UMLItem(wid,hgt),
	_name(new UMLTextItem) , _variable(std::list<UMLTextItem *>()) , _function(std::list<UMLTextItem *>()) 
{
	Port * ports[] = {new Port(0,-hgt/2) , new Port(0, hgt/2),new Port(-wid/2,0) , new Port(wid/2,0)};
	for(int i =0;i<4;i++){
		Port * port  = ports[i];
		port->setParent(this);
		_ports.addPort(port);
	}
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
	_ports.setPortOpen(getState() == ItemState::Selected);
	QPainterPath path = UMLItem::shape();  
	_name->setPosition(_center.x(),_rect().y()+17);
	path.moveTo(_rect().x(),_rect().y()+20);
	path.lineTo(_rect().x()+_rect().width(),_rect().y()+20);
	path.moveTo(_rect().x(),_rect().y()+20+(_rect().height()-20)/2);
	path.lineTo(_rect().x()+_rect().width(),_rect().y()+20+(_rect().height()-20)/2);
	path.addPath(_name->getPath());
	if(_ports.IsPortOpen())
		_addPortToPath(path);
	return path;  
} 
void ClassItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){   
	if(IsInGroup())return;
	Q_UNUSED(widget);   
	QPainterPath temp;
	if(_state & ItemState::Selected || UMLScene::GetScene()->getState()->getSelected() == this){    
		painter->setPen(QPen(Qt::red,2,Qt::SolidLine));  
	}else
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
	//if(IsInGroup()){
	//	getParent()->moveTo(event->scenePos()-pos());
	//}else
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