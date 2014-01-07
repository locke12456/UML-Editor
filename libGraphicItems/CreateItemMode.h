#pragma once
#include "Mode.h"
#include <UMLLine.h>
#include <ClassItem.h>
#include <UseCaseItem.h>
class CreateItemMode : public Mode
{
public:
	CreateItemMode(void);
	~CreateItemMode(void);	
	virtual void generate();
	virtual void modify();
	virtual void contact();
protected:
	UMLLine * _line;
	UMLItem * _item;
};

class CreateClass : public CreateItemMode
{
public:
	CreateClass(void);
	~CreateClass(void);
	virtual void generate();
};

class CreateUseCase : public CreateItemMode
{
public:
	CreateUseCase(void);
	~CreateUseCase(void);
	virtual void generate();
};