#include "UMLBase.h"


UMLBase::UMLBase(void) : _state(None) , _selected(nullptr)
{
}


UMLBase::~UMLBase(void)
{
}

void UMLBase::setState(UMLAddToScene state){
	_state = state;
}

UMLAddToScene UMLBase::getState()
{
	return _state;
}

void * UMLBase::getSelected(){
	return _selected;
}

void UMLBase::setSelected(void* selected)
{
	_selected = selected;
}

void UMLBase::setDrawState(UMLDrawToScene state)
{
	_draw = state;
}

UMLDrawToScene UMLBase::getDrawState()
{
	return _draw;
}


bool UMLBase::IsItemSelect()
{
	return _state >= Select && _state <= Broom;
}

bool UMLBase::IsAddLineItem()
{
	return _state >= Add_association && _state <= Add_dependency;
}
bool UMLBase::IsAddObjectItem()
{
	return _state >= Add_package && _state <= Add_interface;
}
bool UMLBase::IsChangeItemInfo()
{
	return _state >= Add_attribute && _state <= Add_operation;
}
bool UMLBase::IsDrawPress()
{
	return _draw == UMLDrawToScene::DrawPress;
}
bool UMLBase::IsDrawMove()
{
	return _draw == UMLDrawToScene::DrawMove;
}
bool UMLBase::IsDrawFinish()
{
	return _draw == UMLDrawToScene::DrawFinish;
}