#include "GroupMode.h"


GroupMode::GroupMode(void)
{
}
GroupMode::~GroupMode(void)
{
}
void  GroupMode::generate()
{

}
void  GroupMode::contact()
{

}
void  GroupMode::modify()
{

}


Group::Group(void)
{
}


Group::~Group(void)
{
}

void Group::modify()
{
	UMLScene * scene = UMLScene::GetScene();
	UMLGroup * group = scene->getGroup();
	std::list<UMLItem*> *  selected = scene->getSelected();
	if(group == nullptr){
		group = new UMLGroup();
		scene->addItem(group);
	}
	group->buildGroup();
	std::list<UMLItem *>::const_iterator it = selected->begin();
	for(;it!=selected->end();it++)
	{
		group->addMember(*it);
	}
}

UnGroup::UnGroup(void)
{
}


UnGroup::~UnGroup(void)
{
}

void UnGroup::modify()
{

}
