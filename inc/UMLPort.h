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

class UsedPort{
public:
	QPoint origin;
	QPoint *scene;
	UsedPort(){};
};
class UMLPort
{
public:
	UMLPort(void);
	UMLPort(QRectF);
	UMLPort(QPoint p1,QPoint p2);
	~UMLPort(void);
	static double Distence(QPoint,QPoint);
	void setCalc(QGraphicsItem *);
	QPoint FindPonit(QPoint ); 
	QPoint getPotByIndex(int);
	int getIndexByPort(QPoint);
	void setPotByIndex(QPoint,int);
	bool IsPortOpen();
	void setPortOpen(bool);
	int length();
protected:
	QRectF _getPort(QPoint);
	void _addPort(QPoint);
	void _initPorts(QRectF &);
	std::vector<QPoint>& _getPots();
private:
	static double _distence(QPoint,QPoint);
	QPoint _matching(QPoint );
	bool _open;
	std::vector<QPoint> _pots;
	QPoint* _now;
	QGraphicsItem * _calc;
};

