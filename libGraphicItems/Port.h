#pragma once
#include <qpoint.h>
#include "UMLItem.h"
class Port : public QPoint
{
public:
	Port(int x , int y);
	~Port(void);
	void setParent(void *);
	void update();
private:
	void * _parent;
};