#include "UMLBase.h"


UMLBase::UMLBase(void) : _state(None)
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