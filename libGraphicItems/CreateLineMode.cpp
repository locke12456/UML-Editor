#include "CreateLineMode.h"
#include "UMLScene.h"

CreateLineMode::CreateLineMode(void) : _lineTo(nullptr) , _moveTo(nullptr) , _item(nullptr) , _line(nullptr)
{
	_moveTo = new Port(0,0);
	_lineTo = new Port(0,0);
}
CreateLineMode::~CreateLineMode(void)
{

}
void CreateLineMode::generate()
{
	UMLState* _state = UMLScene::GetScene()->getState();
	QPointF pos = UMLScene::GetScene()->MousePosition();
	_lineTo->setPos(pos.x(),pos.y());
	_moveTo->setPos(pos.x(),pos.y());
	_state->setDrawState(UMLDrawToScene::DrawPress);
}

void CreateLineMode::contact()
{
	UMLState* _state = UMLScene::GetScene()->getState();
	QPointF pos = UMLScene::GetScene()->MousePosition();
	if(_line != nullptr){
		_lineTo->setPos(pos.x(),pos.y());
		_line->setTargetPoint(_lineTo);
	}
	_state->setDrawState(UMLDrawToScene::DrawMove);
}

void CreateLineMode::modify()
{
	UMLState* _state = UMLScene::GetScene()->getState();
	std::list<UMLLine *> * _lines = UMLScene::GetScene()->getLineList();
	if(_searchCanMatch(_line)==nullptr){
		UMLScene::GetScene()->removeItem(_line);
	}else{
		_lines->push_back(_line);
		_line = nullptr;
	}
	_state->setDrawState(UMLDrawToScene::DrawFinish);
}

UMLItem * CreateLineMode::_searchCanMatchItem(UMLLine* line,Port* point , _setter setter)
{
	std::list<UMLItem *> * _items = UMLScene::GetScene()->getItemList();
	double min_dst = 0xfffff;
	UMLLine * line_p = nullptr;
	UMLItem* tmp , *setTo = nullptr;
	Port * find, *min_port = nullptr;
	QPointF temp, min_point; 
	std::list<UMLItem*>::const_iterator it = _items->begin();
	for(;it!=_items->end();it++)
	{	
		double dst;
		tmp = *it;
		if(_item == tmp ) 
			continue;
		Port * find = tmp->FindPoint(point->mapToScene());
		if(find == nullptr)continue;
		temp = find->mapToScene();
		dst = PortFactory::Distence(temp,point->mapToScene());
		min_dst = min(min_dst,dst);
		if(dst == min_dst ){
			min_port = find;
			setTo= tmp;
		}
	}
	if( min_port != nullptr )
	{
		_item = setTo;
		(*line.*setter)(min_port);
	}
	else
		return nullptr;
	return setTo;
}

UMLLine * CreateLineMode::_searchCanMatch(UMLLine * line)
{
	UMLState* _state = UMLScene::GetScene()->getState();
	if(line==nullptr || !_state->IsAddLineItem() )return nullptr;
	_item = nullptr;
	if(_searchCanMatchItem(line,_moveTo , &UMLLine::setCurrentPoint) == nullptr)
		return nullptr;
	if(_searchCanMatchItem(line,_lineTo , &UMLLine::setTargetPoint )  == nullptr)
		return nullptr;
	_item = nullptr;
	return line;
}

CreateAssociation::CreateAssociation(void) : CreateLineMode()
{
}
CreateAssociation::~CreateAssociation(void)
{
}
void  CreateAssociation::generate(){
	CreateLineMode::generate();
	_line = new Association(_moveTo,_lineTo);
	UMLScene::GetScene()->addItem(_line);
}

CreateComposition::CreateComposition(void) : CreateLineMode()
{
}
CreateComposition::~CreateComposition(void)
{
}
void  CreateComposition::generate(){
	CreateLineMode::generate();
	_line = new Composition(_moveTo,_lineTo);
	UMLScene::GetScene()->addItem(_line);
}


CreateGeneralization::CreateGeneralization(void) : CreateLineMode()
{
}
CreateGeneralization::~CreateGeneralization(void)
{
}
void  CreateGeneralization::generate(){
	CreateLineMode::generate();
	_line = new Generalization(_moveTo,_lineTo);
	UMLScene::GetScene()->addItem(_line);
}
