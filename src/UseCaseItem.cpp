#include "UseCaseItem.h"
#include "UMLScene.h"

UseCaseItem::UseCaseItem(void) : UMLItem() ,
	_name(new UMLTextItem)
{
}

UseCaseItem::UseCaseItem(qreal wid,qreal hgt) : UMLItem(wid,hgt),
	_name(new UMLTextItem) 
{
	Port * ports[] = {new Port(0,-hgt/2) , new Port(0, hgt/2),new Port(-wid/2,0) , new Port(wid/2,0)};
	for(int i =0;i<4;i++){
		Port * port  = ports[i];
		port->setParent(this);
		_ports.addPort(port);
	}
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
	_ports.setPortOpen(getState() == ItemState::Selected);
	QPainterPath path;
	_center = QPoint(0,0);
	if(IsInGroup())_center = pos();
	path.addEllipse(_rect());    
	_name->setPosition(_center.x(),_center.y()+8);
	path.addPath(_name->getPath());
	if(_ports.IsPortOpen())
		_addPortToPath(path);
	return path;  
} 
void UseCaseItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){   
	Q_UNUSED(widget);   
	if(IsInGroup())return;
	QPainterPath temp;
	
	UMLScene *_parent = UMLScene::GetScene(); 
	if(_state & ItemState::Selected || _parent->getState()->getSelected() == this){    
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
void UseCaseItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
	UMLItem::mousePressEvent(event);
}
void UseCaseItem::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
	UMLItem::mouseMoveEvent(event);
	if(_state != ItemState::Selected)return;
	if(IsInGroup()){
		UMLScene::GetScene()->getGroup()->moveTo(event->scenePos()-pos());
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
