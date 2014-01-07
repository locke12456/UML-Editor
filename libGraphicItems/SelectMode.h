#pragma once
#include "Mode.h"
class SelectMode : public Mode
{
public:
	SelectMode(void);
	~SelectMode(void);
	virtual void generate();
	virtual void modify();
	virtual void contact();
};
class Select : public SelectMode
{
public:
	Select(void);
	~Select(void);
	virtual void modify();
};
class Release : public SelectMode
{
public:
	Release(void);
	~Release(void);
	virtual void modify();
};