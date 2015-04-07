#include "PortFactory.h"

PortFactory::PortFactory(void) : _ports() , _open(false)
{

} 

PortFactory::PortFactory(QRectF rect ) : _ports() , _open(false)
{
}

PortFactory::~PortFactory(void)
{

}


bool PortFactory::IsPortOpen()
{
	return _open;
}

void PortFactory::setPortOpen(bool val)
{
	_open = val;
}
Port* PortFactory::GetPort(int index)
{
	return _ports[index];
}

Port* PortFactory::FindPonit(QPointF point)
{
	return _matching(point);
}

int PortFactory::length()
{
	return _ports.size();
}


void PortFactory::addPort(Port* port){
	_ports.push_back(port);
}
double PortFactory::Distence(QPointF p1,QPointF p2)
{
	return PortFactory::_distence(p1,p2);
}
double PortFactory::_distence(QPointF p1,QPointF p2)
{
	double x1 = p1.x(),x2=p2.x(),y1=p1.y(),y2=p2.y();
	return sqrt(pow(abs(x2 - x1), 2) + pow(abs(y2 - y1), 2));
}

Port* PortFactory::_matching(QPointF point)
{
	Port * p_min = nullptr;
	double b_min = 0xfffff , min_dst = 0xfffff;
	std::vector<Port *>::const_iterator it = _ports.begin();
	for (; it!=_ports.end();it++)
	{
		Port *tmp = *it;
		QPointF p = tmp->mapToScene();
		double dst = _distence(point , p );
		if( dst < MATCHING_LENGTH ){
			min_dst = min(min_dst,dst);
			if(dst == min_dst)
			{
				b_min = min(b_min,dst);
				if(b_min==dst)p_min = tmp;
			}
		}
	}
	return p_min;
}