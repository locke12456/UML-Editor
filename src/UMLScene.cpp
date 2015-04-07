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
	_items(std::list<UMLItem*>()) , _lines(std::list<UMLLine*>()) 
	, _group(nullptr), _state(), _currentMode(nullptr)
{
	_init();
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
	_modes.insert(	std::make_pair(SelectItemMode				,new SelectMode()				)  );
	_modes.insert(	std::make_pair(GroupItemMode				,new Group()				)  );
	_modes.insert(	std::make_pair(UnGroupItemMode				,new UnGroup()				)  );
	//_modes.insert(	std::make_pair(Broom				,ui->actionBroom				)  );
	//_modes.insert(	std::make_pair(Add_package			,ui->actionAdd_package			)  );
	_modes.insert(	std::make_pair(Add_class					,new CreateClass()			)  );
	//_modes.insert(	std::make_pair(Add_interface		,ui->actionAdd_interface		)  );
	_modes.insert(	std::make_pair(Add_use_case					,new CreateUseCase()			)  );
	_modes.insert(	std::make_pair(Add_association				,new CreateAssociation()		)  );
	//_modes.insert(	std::make_pair(Add_uni_association	,ui->actionAdd_uni_association	)  );
	//_modes.insert(	std::make_pair(Add_aggregation		,ui->actionAdd_aggregation		)  );
	_modes.insert(	std::make_pair(Add_composition				,new CreateComposition()		)  );
	//_modes.insert(	std::make_pair(Add_association_end	,ui->actionAdd_association_end	)  );
	_modes.insert(	std::make_pair(Add_generalization			,new CreateGeneralization()	)  );
	//_modes.insert(	std::make_pair(Add_Realization		,ui->actionAdd_Realization		)  );
	//_modes.insert(	std::make_pair(Add_dependency		,ui->actionAdd_dependency		)  );
	//_modes.insert(	std::make_pair(Add_attribute		,ui->actionAdd_attribute		)  );
	//_modes.insert(	std::make_pair(Add_operation		,ui->actionAdd_operation		)  );
	//_modes.insert(	std::make_pair(Add_data_type		,ui->actionAdd_data_type		)  );
}

UMLState* UMLScene::getState(){
	return &_state;
}
bool UMLScene::IsSelected(UMLItem* item){
	std::list<UMLItem*>::const_iterator it = std::find(_selected.begin(),_selected.end() , item);
	return it!=_selected.end();
}
void UMLScene::setGroup(UMLGroup * group)
{
	_group = group;
}
UMLGroup * UMLScene::getGroup()
{
	return _group;
}
void UMLScene::setSelected(std::list<UMLItem*> * select)
{
	_selected = *select;
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
Mode* UMLScene::GetCurrentMode()
{
	return _currentMode;
}

void UMLScene::setItemName()
{

}

void UMLScene::setItemName(QString text)
{
	UMLItem* item = (UMLItem*)_state.getSelected();
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