#include "Composition.h"

Composition::Composition(void) : UMLLine() 
{

}

Composition::Composition(Port* p1,Port* p2) : UMLLine(p1,p2)
{

}

Composition::~Composition(void)
{
}
QPainterPath Composition::shape(){   
	typedef QPainterPath (Composition::*flag)() ;
	QPainterPath path;
	flag point[] = { &Composition::_getUpFlag , &Composition::_getDownFlag , &Composition::_getLeftFlag , &Composition::_getRightFlag };

	path.addPath( (*this.*point[(int)getTargetPosition()-1])() );

	return path;  
} 
void Composition::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){   
	Q_UNUSED(widget);   
	QPainterPath temp;

	if(_state & ItemState::Selected){    
		painter->setPen(QPen(Qt::red,2,Qt::SolidLine));  
	}
	if(_state & ItemState::Hover){    
		painter->setPen(QPen(Qt::red,1,Qt::SolidLine));   
	}
	QPainterPath path = shape();
	painter->fillPath(path,Qt::black);
	painter->drawPath(path);
} 
void Composition::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
	UMLLine::mousePressEvent(event);
}
void Composition::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
	UMLLine::mouseMoveEvent(event);
	if(_state != ItemState::Selected)return;
	setPos(event->scenePos().x(),event->scenePos().y());
}
void Composition::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
	UMLLine::mouseReleaseEvent(event);
}

void Composition::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
	UMLLine::hoverEnterEvent(event);
}

void Composition::hoverMoveEvent(QGraphicsSceneHoverEvent *event)
{
	UMLLine::hoverMoveEvent(event);
}

void Composition::hoverLeaveEvent(QGraphicsSceneHoverEvent *event)
{
	UMLLine::hoverLeaveEvent(event);
}
QPainterPath Composition::_getLine(){
	QPainterPath path ;
	path.moveTo(getLine().p1());
	path.lineTo(getLine().p2());
	return path;
}
QPainterPath Composition::_getLeftFlag()
{
	QPainterPath path;
	QPointF up,down,left,right,cur;
	//char* _point[] = {"up","down","left","right"};
	QPointF *point[] = {&up,&down,&left,&right};
	up = QPointF( getLine().p1().x() - 5.0, getLine().p1().y() - 5.0);
	left = QPointF( getLine().p1().x()-10.0, getLine().p1().y() );
	down = QPointF( getLine().p1().x() -5.0, getLine().p1().y() + 5.0 ) ;
	right = QPointF( getLine().p1().x() , getLine().p1().y() ) ;
	path.moveTo( left );
	path.lineTo( down );
	path.lineTo( right );
	path.lineTo( up );
	path.lineTo( left );
	cur = *point[(int)getTargetPosition()-1];
	//qDebug()<<_point[(int)getTargetPosition()-1];
	path.moveTo(cur);
	path.lineTo(getLine().p2());
	return path;
}
QPainterPath Composition::_getRightFlag()
{
	QPainterPath path;
	QPointF up,down,left,right,cur;
	//char* _point[] = {"up","down","left","right"};
	QPointF *point[] = {&up,&down,&left,&right};
	up = QPointF( getLine().p1().x() + 5.0 , getLine().p1().y() - 5.0);
	left = QPointF( getLine().p1().x() , getLine().p1().y() );
	down =  QPointF( getLine().p1().x()+ 5.0, getLine().p1().y()+5.0 ) ;
	right =  QPointF( getLine().p1().x()+ 10.0, getLine().p1().y() ) ;
	path.moveTo( right );
	path.lineTo( down );
	path.lineTo( left );
	path.lineTo( up );
	path.lineTo( right );
	cur = *point[(int)getTargetPosition()-1];
	//qDebug()<<_point[(int)getTargetPosition()-1];
	path.moveTo(cur);
	path.lineTo(getLine().p2());
	return path;
}
QPainterPath Composition::_getUpFlag()
{
	QPainterPath path;
	QPointF up,down,left,right,cur;
	//char* _point[] = {"up","down","left","right"};
	QPointF *point[] = {&up,&down,&left,&right};
	up = QPointF( getLine().p1().x(), getLine().p1().y() -10.0);
	left = QPointF( getLine().p1().x()-5.0, getLine().p1().y()-5.0 );
	down =  QPointF( getLine().p1().x(), getLine().p1().y() ) ;
	right =  QPointF( getLine().p1().x()+5.0, getLine().p1().y()-5.0 ) ;
	path.moveTo( up );
	path.lineTo( left );
	path.lineTo( down );
	path.lineTo( right );
	path.lineTo( up );
	cur = *point[(int)getTargetPosition()-1];
	//qDebug()<<_point[(int)getTargetPosition()-1];
	path.moveTo(cur);
	path.lineTo(getLine().p2());
	return path;
}
QPainterPath Composition::_getDownFlag()
{
	QPainterPath path;
	QPointF up,down,left,right,cur;
	//char* _point[] = {"up","down","left","right"};
	QPointF *point[] = {&up,&down,&left,&right};
	up = QPointF( getLine().p1().x(), getLine().p1().y() );
	left = QPointF( getLine().p1().x()-5.0, getLine().p1().y()+5.0 );
	down =  QPointF( getLine().p1().x()+0, getLine().p1().y()+10.0 ) ;
	right =  QPointF( getLine().p1().x()+5.0, getLine().p1().y()+5.0 ) ;
	path.moveTo( down );
	path.lineTo( left );
	path.lineTo( up );
	path.lineTo( right );
	path.lineTo( down );
	cur = *point[(int)getTargetPosition()-1];
	//qDebug()<<_point[(int)getTargetPosition()-1];
	path.moveTo(cur);
	path.lineTo(getLine().p2());
	return path;
}