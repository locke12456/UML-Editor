#pragma once
#include "CreateLineMode.h"
class SelectMode : public CreateLineMode
{
public:
	SelectMode(void);
	~SelectMode(void);
	virtual void generate();
	virtual void contact();
	virtual void modify();
};