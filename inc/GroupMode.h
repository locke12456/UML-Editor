#pragma once
#include "Mode.h"
#include "UMLScene.h"

class GroupMode : public Mode
{
public:
	GroupMode(void);
	~GroupMode(void);
	virtual void generate();
	virtual void modify();
	virtual void contact();
};
class Group: public GroupMode
{
public:
	Group(void);
	~Group(void);
	virtual void modify();
};

class UnGroup: public GroupMode
{
public:
	UnGroup(void);
	~UnGroup(void);
	virtual void modify();
};
