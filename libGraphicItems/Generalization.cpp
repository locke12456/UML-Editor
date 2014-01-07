#include "Generalization.h"

Generalization::Generalization(void) : UMLLine()
{

}

Generalization::Generalization(Port* p1,Port* p2) : UMLLine(p1,p2)
{

}

Generalization::~Generalization(void)
{
}
QPainterPath Generalization::shape(){ 
	typedef QPainterPath (Generalization::*flag)() ;
	QPainterPath path;
	flag point[] = {&Generalization::_getUpFlag,&Generalization::_getDownFlag,&Generalization::_getLeftFlag,&Generalization::_getRightFlag};

	path.addPath((*this.*point[(int)getTargetPosition()-1])());
	//qDebug()<<_point[(int)getTargetPosition()-1];
	return path;  
} 
void Generalization::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){   
	Q_UNUSED(widget);   
	QPainterPath temp;

	//painter->setPen(QPen(Qt::red,1,Qt::SolidLine));   
	if(_state & ItemState::Selected){    
		painter->setPen(QPen(Qt::red,2,Qt::SolidLine));  
	}
	
	QPainterPath path = shape();
	painter->fillPath(path,Qt::black);
	painter->drawPath(path);
} 
void Generalization::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
	UMLLine::mousePressEvent(event);
}
void Generalization::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
	UMLLine::mouseMoveEvent(event);
	if(_state != ItemState::Selected)return;
	setPos(event->scenePos().x(),event->scenePos().y());
}
void Generalization::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
	UMLLine::mouseReleaseEvent(event);
}

void Generalization::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
	UMLLine::hoverEnterEvent(event);
}

void Generalization::hoverMoveEvent(QGraphicsSceneHoverEvent *event)
{
	UMLLine::hoverMoveEvent(event);
}

void Generalization::hoverLeaveEvent(QGraphicsSceneHoverEvent *event)
{
	UMLLine::hoverLeaveEvent(event);
}
QPainterPath Generalization::_getLine(){
	QPainterPath path ;
	path.moveTo(getLine().p1());
	path.lineTo(getLine().p2());
	return path;
}
QPainterPath Generalization::_getLeftFlag()
{
	QPainterPath path ;
	QPointF up,down,left,right,tar;
	left = QPointF( getLine().p2().x(), getLine().p2().y() );
	up = QPointF( getLine().p2().x()+FLAG_SIZE, getLine().p2().y()-FLAG_SIZE );
	down =  QPointF( getLine().p2().x()+FLAG_SIZE, getLine().p2().y()+FLAG_SIZE ) ;
	path.moveTo(getLine().p2());
	path.lineTo( up );
	path.lineTo( down );
	path.lineTo( left );
	tar = QPointF( getLine().p2().x()+FLAG_SIZE, getLine().p2().y() ) ;
	path.moveTo(getLine().p1());
	path.lineTo(tar);
	return path;
}
QPainterPath Generalization::_getRightFlag()
{
	QPainterPath path ;
	QPointF up,down,left,right,tar;
	right = QPointF( getLine().p2().x(), getLine().p2().y() );
	up = QPointF( getLine().p2().x()-FLAG_SIZE, getLine().p2().y()-FLAG_SIZE );
	down =  QPointF( getLine().p2().x()-FLAG_SIZE, getLine().p2().y()+FLAG_SIZE ) ;
	path.moveTo(getLine().p2());
	path.lineTo( up );
	path.lineTo( down );
	path.lineTo( right );
	tar = QPointF( getLine().p2().x()-FLAG_SIZE, getLine().p2().y() ) ;
	path.moveTo(getLine().p1());
	path.lineTo(tar);
	return path;
}

QPainterPath Generalization::_getUpFlag()
{
	QPainterPath path ;
	QPointF up,down,left,right,tar;
	up = QPointF( getLine().p2().x(), getLine().p2().y() );
	left = QPointF( getLine().p2().x()-FLAG_SIZE, getLine().p2().y()+FLAG_SIZE );
	right =  QPointF( getLine().p2().x()+FLAG_SIZE, getLine().p2().y()+FLAG_SIZE ) ;
	path.moveTo(getLine().p2());
	path.lineTo( left );
	path.lineTo( right );
	path.lineTo( up );
	tar = QPointF( getLine().p2().x(), getLine().p2().y()+FLAG_SIZE ) ;
	path.moveTo(getLine().p1());
	path.lineTo(tar);
	return path;
}
QPainterPath Generalization::_getDownFlag()
{
	QPainterPath path ;
	QPointF up,down,left,right,tar;
	up = QPointF( getLine().p2().x(), getLine().p2().y() );
	left = QPointF( getLine().p2().x()-FLAG_SIZE, getLine().p2().y()-FLAG_SIZE );
	right =  QPointF( getLine().p2().x()+FLAG_SIZE, getLine().p2().y()-FLAG_SIZE ) ;
	path.moveTo(getLine().p2());
	path.lineTo( left );
	path.lineTo( right );
	path.lineTo( up );
	tar = QPointF( getLine().p2().x(), getLine().p2().y()-FLAG_SIZE ) ;
	path.moveTo(getLine().p1());
	path.lineTo(tar);
	return path;
}