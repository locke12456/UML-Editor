#include "SelectMode.h"
#include "UMLScene.h"
#include "ItemSelect.h"

SelectMode::SelectMode(void)
{
}
SelectMode::~SelectMode(void)
{
}
void  SelectMode::generate()
{
	CreateLineMode::generate();
	//if(_line!=nullptr)((ItemSelect*)_line)->releaseAll(*UMLScene::GetScene()->getItemList());
	ItemSelect* line = new ItemSelect(_moveTo,_lineTo);
	UMLScene::GetScene()->addItem(line);
	_line = line;
	((ItemSelect*)_line)->releaseAll(*UMLScene::GetScene()->getItemList());
}
void SelectMode::contact(){
	if(_line == nullptr)return;
	CreateLineMode::contact();
	_line->findInRange(*UMLScene::GetScene()->getItemList());
}
void  SelectMode::modify()
{
	if(_line == nullptr)return;
	UMLState* _state = UMLScene::GetScene()->getState();
	std::list<UMLItem *> list = ((ItemSelect*)_line)->getSelectedItems(*UMLScene::GetScene()->getItemList());
	if(list.size()>0)
	{
		_item = *list.begin();
		_state->setSelected(_item);
		UMLScene::GetScene()->setSelected(&list);
	}else _state->setSelected(nullptr);
	UMLScene::GetScene()->removeItem(_line);
	_line = nullptr;
}
