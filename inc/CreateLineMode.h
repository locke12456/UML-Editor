#pragma once
#include "Mode.h"
#include <UMLItem.h>
#include <Association.h>
#include <Generalization.h>
#include <Composition.h>
class CreateLineMode : public Mode
{
public:
	CreateLineMode(void);
	~CreateLineMode(void);
	virtual void generate();
	virtual void modify();
	virtual void contact();
protected:
	UMLLine * _line;
	UMLItem * _item;
	Port * _moveTo;
	Port * _lineTo;
private:	
	typedef void (UMLLine::*_setter)(Port*);
	UMLLine * _searchCanMatch(UMLLine *);
	UMLItem * _searchCanMatchItem(UMLLine *,Port* , _setter);
};
class CreateAssociation : public CreateLineMode{
public:
	CreateAssociation();
	~CreateAssociation();
	virtual void generate();
};
class CreateGeneralization : public CreateLineMode{
public:
	CreateGeneralization();
	~CreateGeneralization();
	virtual void generate();
};
class CreateComposition : public CreateLineMode{
public:
	CreateComposition();
	~CreateComposition();
	virtual void generate();
};