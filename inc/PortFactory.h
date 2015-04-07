#pragma once
#include <iostream>
#include <vector>

#include <QPoint>
#include <QRect>
#include <QGraphicsItem>
#ifndef max 
#define max(a,b)    (((a) > (b)) ? (a) : (b))
#define min(a,b)    (((a) < (b)) ? (a) : (b))
#endif
#define MATCHING_LENGTH 64

class Port{
public:
	Port(int x , int y ) : _origin(x,y) , _parent(nullptr) {  };
	void setPos(int x , int y){
		_origin = QPointF(x,y);
	};
	QPointF mapToScene(){
		return (_parent != nullptr) ?_parent->mapToScene(_origin) : _origin;
	};
	QPointF mapToItem(){
		return _origin;
	};
	QRectF getRect(){
		return QRectF(_origin.x()-1,_origin.y()-1,2,2);
	};
	void setParent(QGraphicsItem * parent){
		_parent = parent;
	};
private:
	QPointF _origin;
	QGraphicsItem * _parent;
};
class PortFactory
{
public:
	PortFactory(void);
	PortFactory(QRectF);
	PortFactory(QPoint* p1,QPoint* p2);
	~PortFactory(void);
	static double Distence(QPointF,QPointF);
	Port * GetPort(int index);
	Port* FindPonit(QPointF); 
	bool IsPortOpen();
	void setPortOpen(bool);
	int length();
	void addPort(Port *);
protected:
	std::vector<QPoint>& _getPorts();
private:
	static double _distence(QPointF,QPointF);
	Port* _matching(QPointF);
	bool _open;
	std::vector<Port *> _ports;
	QPoint* _now;
};

