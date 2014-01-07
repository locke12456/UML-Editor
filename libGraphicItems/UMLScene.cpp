#include "UMLScene.h"

UMLScene * UMLScene::_singleton = nullptr;

UMLScene * UMLScene::GetScene()
{
	if(_singleton == nullptr)_singleton = new UMLScene();
	return _singleton;
}

void UMLScene::Destory()
{
	delete _singleton;
	_singleton = nullptr;
}

UMLScene::UMLScene(void) : 
	_items(std::list<UMLItem*>()) , _lines(std::list<UMLLine*>()) ,
	_line(nullptr) , _group(nullptr)
	, _moveTo(nullptr) , _lineTo(nullptr)  
	, _state()
{
	_init();
	_moveTo = new Port(0,0);
	_lineTo = new Port(0,0);
	//_moveTo->setParent(this);
}


UMLScene::~UMLScene(void)
{
	while(_items.size()>0){
		std::list<UMLItem*>::iterator it = _items.begin();
		UMLItem *item = *it;
		removeItem(item);
		_items.pop_back();
	}
}

void UMLScene::_init()
{
	_modes.insert(	std::make_pair(SelectItemMode				,new Select()				)  );
	_modes.insert(	std::make_pair(ReleaseItemMode				,new Release()				)  );
	_modes.insert(	std::make_pair(GroupItemMode				,new Group()				)  );
	_modes.insert(	std::make_pair(UnGroupItemMode				,new UnGroup()				)  );
	//_modes.insert(	std::make_pair(Broom				,ui->actionBroom				)  );
	//_modes.insert(	std::make_pair(Add_package			,ui->actionAdd_package			)  );
	_modes.insert(	std::make_pair(Add_class			,new CreateClass()			)  );
	//_modes.insert(	std::make_pair(Add_interface		,ui->actionAdd_interface		)  );
	_modes.insert(	std::make_pair(Add_use_case			,new CreateUseCase()			)  );
	_modes.insert(	std::make_pair(Add_association		,new CreateAssociation()		)  );
	//_modes.insert(	std::make_pair(Add_uni_association	,ui->actionAdd_uni_association	)  );
	//_modes.insert(	std::make_pair(Add_aggregation		,ui->actionAdd_aggregation		)  );
	_modes.insert(	std::make_pair(Add_composition		,new CreateComposition()		)  );
	//_modes.insert(	std::make_pair(Add_association_end	,ui->actionAdd_association_end	)  );
	_modes.insert(	std::make_pair(Add_generalization	,new CreateGeneralization()	)  );
	//_modes.insert(	std::make_pair(Add_Realization		,ui->actionAdd_Realization		)  );
	//_modes.insert(	std::make_pair(Add_dependency		,ui->actionAdd_dependency		)  );
	//_modes.insert(	std::make_pair(Add_attribute		,ui->actionAdd_attribute		)  );
	//_modes.insert(	std::make_pair(Add_operation		,ui->actionAdd_operation		)  );
	//_modes.insert(	std::make_pair(Add_data_type		,ui->actionAdd_data_type		)  );
}

UMLState* UMLScene::getState(){
	return &_state;
}

UMLGroup * UMLScene::getGroup()
{
	return _group;
}
std::list<UMLItem*> * UMLScene::getSelected()
{
	return &_selected;
}

std::list<UMLItem*> * UMLScene::getItemList()
{
	return &_items;
}

std::list<UMLLine*> * UMLScene::getLineList()
{
	return &_lines;
}

QPointF UMLScene::MousePosition()
{
	return _pos;
}
void UMLScene::ChangeCurrentMode(UMLAddToScene state)
{
	_changeCurrentMode(state);
}

void UMLScene::setItemName()
{

}

void UMLScene::setItemName(QString text)
{
	UMLItem* item = (UMLItem*)getSelected();
	if(item==nullptr)return;
	item->setName(text , 16);
}


void UMLScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
	_pos = event->scenePos();
	if(_currentMode != nullptr) _currentMode->generate();
	update();
	QGraphicsScene::mousePressEvent(event);
}

void UMLScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
	_pos = event->scenePos();
	if(_currentMode != nullptr) _currentMode->contact();
	update();
	QGraphicsScene::mouseMoveEvent(event);
}

void UMLScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
	_pos = event->scenePos();
	if(_currentMode != nullptr) _currentMode->modify();
	update();
	QGraphicsScene::mouseMoveEvent(event);
}
void UMLScene::_changeCurrentMode(UMLAddToScene state)
{
	_state.setModeState(state);
	Actions::const_iterator mode = _modes.find(state);
	_currentMode =mode ==_modes.end()?nullptr : mode->second;
}
void UMLScene::_mousePress(QPointF pos)
{	
	_pos = pos;
	_addToScene(pos);
	if(_state.IsAddLineItem()){
		_state.setDrawState(UMLDrawToScene::DrawPress);
	}
}
void UMLScene::_mouseMove(QPointF pos)
{
	_pos = pos;
	if(_line != nullptr){
		_lineTo->setPos(pos.x(),pos.y());
		_line->setTargetPoint(_lineTo);

		if(_state.IsItemSelect())
		{
			_line->findInRange(_items);
		}
	}
	if(_state.IsAddLineItem())
	{
		_state.setDrawState(UMLDrawToScene::DrawMove);
	}
}
void UMLScene::_mouseRelease(QPointF pos)
{
	_pos = pos;
	if(_state.getModeState() == UMLAddToScene::SelectItemMode )_releaseSelect();
	
}

void UMLScene::_addToScene(QPointF pos)
{
	switch(_state.getModeState()){
	case UMLAddToScene::SelectItemMode:
		_initSelect(pos);
		break;
	case UMLAddToScene::Add_class:
		_items.push_back(_addClass(pos));
		break;
	case UMLAddToScene::Add_use_case:
		_items.push_back(_addUseCaseItem(pos));
		break;
	default:
		_line = nullptr;
		_item = nullptr;
	}
}

void UMLScene::_addToGroup()
{
	/*if(_group == nullptr){
	_group = new Group();
	addItem(_group);
	}
	_group->buildGroup();
	std::list<UMLItem *>::const_iterator it = _selected.begin();
	for(;it!=_selected.end();it++)
	{
	_group->addMember(*it);
	}*/

}

ClassItem * UMLScene::_addClass(QPointF pos)
{
	ClassItem *item = new ClassItem(100,80);
	item->setName("Class",16);
	item->setPos(pos);
	//item->setParent(this);
	addItem(item);
	_item = item;
	return item;
}

UseCaseItem * UMLScene::_addUseCaseItem(QPointF pos)
{
	UseCaseItem *item = new UseCaseItem(120,100);
	item->setName("UseCase",16);
	item->setPos(pos);
	//item->setParent(this);
	addItem(item);
	_item = item;
	return item;
}

void UMLScene::_initSelect(QPointF pos)
{
	_lineTo->setPos(pos.x(),pos.y());
	_moveTo->setPos(pos.x(),pos.y());
	ItemSelect * line = new ItemSelect(_moveTo,_lineTo);
	//line->setParent(this);
	addItem(line);
	line->releaseAll(_items);
	_line = line;
}

void UMLScene::_releaseSelect()
{
	if(_line == nullptr)return;
	std::list<UMLItem *> list = ((ItemSelect*)_line)->getSelectedItems(_items);
	if(list.size()>0)
	{
		_item = *list.begin();
		_state.setSelected(_item);
		_selected = list;
	}else _state.setSelected(nullptr);
	removeItem(_line);
	_line = nullptr;
}

Association * UMLScene::_addAssociation(QPointF pos)
{
	_lineTo->setPos(pos.x(),pos.y());
	_moveTo->setPos(pos.x(),pos.y());
	Association * line = new Association(_moveTo,_lineTo);
	//line->setParent(this);
	addItem(line);
	_line = line;
	return line;
}
Composition * UMLScene::_addComposition(QPointF pos)
{
	_lineTo->setPos(pos.x(),pos.y());
	_moveTo->setPos(pos.x(),pos.y());
	Composition * line = new Composition(_moveTo,_lineTo);
	//line->setParent(this);
	addItem(line);
	_line = line;
	return line;
}
Generalization * UMLScene::_addGeneralization(QPointF pos)
{
	_lineTo->setPos(pos.x(),pos.y());
	_moveTo->setPos(pos.x(),pos.y());
	Generalization * line = new Generalization(_moveTo,_lineTo);
	//line->setParent(this);
	addItem(line);
	_line = line;
	return line;
}