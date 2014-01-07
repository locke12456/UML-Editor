#include "UMLState.h"


UMLState::UMLState(void) : _state(None) , _selected(nullptr)
{
}


UMLState::~UMLState(void)
{
}

void UMLState::setModeState(UMLAddToScene state){
	_state = state;
}

UMLAddToScene UMLState::getModeState()
{
	return _state;
}

void * UMLState::getSelected(){
	return _selected;
}

void UMLState::setSelected(void* selected)
{
	_selected = selected;
}

void UMLState::setDrawState(UMLDrawToScene state)
{
	_draw = state;
}

UMLDrawToScene UMLState::getDrawState()
{
	return _draw;
}


bool UMLState::IsItemSelect()
{
	return _state >= SelectItemMode && _state <= Broom;
}

bool UMLState::IsAddLineItem()
{
	return _state >= Add_association && _state <= Add_dependency;
}
bool UMLState::IsAddObjectItem()
{
	return _state >= Add_package && _state <= Add_interface;
}
bool UMLState::IsChangeItemInfo()
{
	return _state >= Add_attribute && _state <= Add_operation;
}
bool UMLState::IsDrawPress()
{
	return _draw == UMLDrawToScene::DrawPress;
}
bool UMLState::IsDrawMove()
{
	return _draw == UMLDrawToScene::DrawMove;
}
bool UMLState::IsDrawFinish()
{
	return _draw == UMLDrawToScene::DrawFinish;
}