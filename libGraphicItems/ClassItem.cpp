#include "ClassItem.h"


ClassItem::ClassItem(void) : UMLItem() , 
							_name(new UMLTextItem)
{
}

ClassItem::ClassItem(qreal wid,qreal hgt) : UMLItem(wid,hgt),
	_name(new UMLTextItem) , _variable(std::list<UMLTextItem *>()) , _function(std::list<UMLTextItem *>())
{

}

ClassItem::~ClassItem(void)
{
	delete _name;
}
void ClassItem::setClassName(QString text,int size){
	_name->setText(text.toStdString());
	_name->setFont(DEFAULT_FONT,size);
}
QPainterPath ClassItem::shape()const{   
	QPainterPath path = UMLItem::shape();  
	_name->setPosition(_rect().x(),_rect().y()+17);
	path.moveTo(_rect().x(),_rect().y()+20);
	path.lineTo(_rect().x()+_rect().width(),_rect().y()+20);
	path.addPath(_name->getPath());

	return path;  
} 
void ClassItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){   
    Q_UNUSED(widget);   
	
	if(_state & ItemState::Selected){    
		painter->setPen(QPen(Qt::red,2,Qt::SolidLine));   
    }
	if(_state & ItemState::Hover){    
		painter->setPen(QPen(Qt::red,1,Qt::SolidLine));   
    }
	painter->drawPath(shape());
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