#include "UMLPort.h"

UMLPort::UMLPort(void) : _pots()
{

} 
UMLPort::UMLPort(QRectF rect ) : _pots() , _calc(nullptr)
{
	_initPorts(rect);
}
UMLPort::UMLPort(QPoint p1,QPoint p2) : _pots() 
{
	_pots.push_back(p1);
	_pots.push_back(p2);
}

UMLPort::~UMLPort(void)
{

}
double UMLPort::Distence(QPoint p1,QPoint p2){
	return _distence(p1,p2);
}
void UMLPort::setCalc(QGraphicsItem * calc)
{
	_calc = calc;
}
QPoint UMLPort::FindPonit(QPoint point)
{
	return _matching(point);
}
int UMLPort::length()
{
	return _pots.size();
}
void UMLPort::_initPorts(QRectF & rect)
{
	double x_shift = rect.width()/4;
	double y_shift = rect.height()/4;
	double width = rect.x()+rect.width();
	double height = rect.y()+rect.height();
	for ( double i = rect.x(); i <= width ; i += x_shift){
		for ( double j = rect.y(); j <= height ; j += y_shift)
		{
			if(!(j==rect.y()||j==height||i==rect.x()||i==width))continue;
			QPoint point(i,j);
			_pots.push_back(point);
		}
	}
	x_shift=0;
	return;
}
void UMLPort::_addPort(QPoint port){
	_pots.push_back(port);
}
QRectF UMLPort::_getPort(QPoint pot){
	return QRectF(pot.x()-1,pot.y()-1,2,2);
}
void UMLPort::setPotByIndex(QPoint point,int index){
	_pots[index] = point;
}
QPoint UMLPort::getPotByIndex(int index){
	return _pots[index];
}
std::vector<QPoint>& UMLPort::_getPots(){
	return _pots;
}
double UMLPort::_distence(QPoint p1,QPoint p2)
{
	double x1 = p1.x(),x2=p2.x(),y1=p1.y(),y2=p2.y();
	return sqrt(pow(abs(x2 - x1), 2) + pow(abs(y2 - y1), 2));
}
QPoint UMLPort::_matching(QPoint point)
{
	QPoint p_min;
	double b_min = 0xfffff , min_dst = 0xfffff;
	std::vector<QPoint>::const_iterator it = _pots.begin();
	for (; it!=_pots.end();it++)
	{
		QPoint tmp = *it;
		QPoint p = QPoint(_calc->mapToScene(tmp).x(),_calc->mapToScene(tmp).y());
		double dst = _distence(point , p );
		min_dst = min(min_dst,dst);
		if(dst == min_dst)
		{
			b_min = min(b_min,dst);
			if(b_min==dst)p_min = p;
		}
	}
	return p_min;
}