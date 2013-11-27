#include "UMLScene.h"


UMLScene::UMLScene(void) : 
	_items(std::list<UMLItem*>()) , _lines(std::list<UMLLine*>()) ,
	_line(nullptr) , _group(nullptr)
	, _moveTo() , _lineTo() 
{

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

void UMLScene::setGroup()
{
	_addToGroup();
}
void UMLScene::setUnGroup()
{
	_group->releaseGroup();
	if(_group->getGroup() == nullptr){
		removeItem(_group);
		_group = nullptr;
	}
}
void UMLScene::moveTo(QPointF point)
{
	std::list<UMLItem *>::const_iterator it = _group->getGroup()->begin();
	for(;it!=_group->getGroup()->end();it++)
	{
		UMLItem * item = *it;
		item->setPos(item->pos()+point);
	}
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

void UMLScene::update_lines()
{
	std::list<UMLLine*>::const_iterator it = _lines.begin();
	for(;it!=_lines.end();it++)
	{
		UMLLine* line = *it;
		line->getLine();
	}
}

void UMLScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
	_mousePress(event->scenePos());
	update();
	QGraphicsScene::mousePressEvent(event);
}

void UMLScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
	_mouseMove(event->scenePos());
	update();
	QGraphicsScene::mouseMoveEvent(event);
}

void UMLScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
	_mouseRelease(event->scenePos());
	update();
	QGraphicsScene::mouseMoveEvent(event);
}

UMLItem * UMLScene::_searchCanMatchItem(UMLLine* line,QPoint point,_setter setter)
{
	double min_dst = 0xfffff;
	UMLLine * line_p = nullptr;
	UMLItem* tmp , *setTo = nullptr;
	QPoint temp, min_point; 
	std::list<UMLItem*>::const_iterator it = _items.begin();
	for(;it!=_items.end();it++)
	{	
		double dst;
		tmp = *it;
		if(_item == tmp ) 
			continue;
		temp = tmp->FindPonit(point);
		dst = UMLPort::Distence(temp,point);
		min_dst = min(min_dst,dst);
		if(dst == min_dst ){
			min_point = temp;
			setTo= tmp;
		}
	}
	if( min_point.x()!=-1000 )
	{
		_item = setTo;
		(*line.*setter)(setTo,_item->getIndexByPort(min_point));
	}
	else
		return nullptr;
	return setTo;
}

UMLLine * UMLScene::_searchCanMatch(UMLLine * line)
{
	if(line==nullptr || !IsAddLineItem() )return nullptr;
	_item = nullptr;
	if(_searchCanMatchItem(line,_moveTo,&UMLLine::setParentItem) == nullptr)
		return nullptr;
	if(_searchCanMatchItem(line,_lineTo,&UMLLine::setTargetItem) == nullptr)
		return nullptr;
	_item = nullptr;
	return line;
}

void UMLScene::_mousePress(QPointF pos)
{
	std::list<UMLItem*>::const_iterator it = _items.begin();
	for(;it!=_items.end();it++){
		UMLItem* item = *it;
		item->setState(ItemState::Normal);
		item->setPortOpen(false);
	}
	setSelected(nullptr);
	_addToScene(pos);
	if(IsAddLineItem()){
		setDrawState(UMLDrawToScene::DrawPress);
	}
}
void UMLScene::_mouseMove(QPointF pos)
{
	if(_line != nullptr){
		_lineTo = QPoint(pos.x(),pos.y());
		_line->setTargetPoint(_lineTo);

		if(IsItemSelect())
		{
			_line->findInRange(_items);
		}
	}
	if(IsAddLineItem())
	{
		setDrawState(UMLDrawToScene::DrawMove);
	}
}
void UMLScene::_mouseRelease(QPointF pos)
{
	if(getState() == UMLAddToScene::Select )_releaseSelect();
	if(IsAddLineItem()){
		if(_searchCanMatch(_line)==nullptr){
			removeItem(_line);
		}else{
			_lines.push_back(_line);
			_line = nullptr;
		}
		setDrawState(UMLDrawToScene::DrawFinish);
	}
}

void UMLScene::_addToScene(QPointF pos)
{
	switch(_state){
	case UMLAddToScene::Select:
		_initSelect(pos);
		break;
	case UMLAddToScene::Add_class:
		_items.push_back(_addClass(pos));
		break;
	case UMLAddToScene::Add_use_case:
		_items.push_back(_addUseCaseItem(pos));
		break;
	case UMLAddToScene::Add_generalization:
		_addGeneralization(pos);
		break;
	case UMLAddToScene::Add_composition:
		(_addComposition(pos));
		break;
	case UMLAddToScene::Add_association:
		(_addAssociation(pos));
		break;
	default:
		_line = nullptr;
		_item = nullptr;
	}
}

void UMLScene::_addToGroup()
{
	if(_group == nullptr){
		_group = new Group();
		addItem(_group);
	}
	_group->buildGroup();
	std::list<UMLItem *>::const_iterator it = _selected.begin();
	for(;it!=_selected.end();it++)
	{
		_group->addMember(*it);
	}
	
}

ClassItem * UMLScene::_addClass(QPointF pos)
{
	ClassItem *item = new ClassItem(100,80);
	item->setName("Class",16);
	item->setPos(pos);
	item->setParent(this);
	addItem(item);
	_item = item;
	return item;
}

UseCaseItem * UMLScene::_addUseCaseItem(QPointF pos)
{
	UseCaseItem *item = new UseCaseItem(120,100);
	item->setName("UseCase",16);
	item->setPos(pos);
	item->setParent(this);
	addItem(item);
	_item = item;
	return item;
}

void UMLScene::_initSelect(QPointF pos)
{
	_lineTo =QPoint(pos.x(),pos.y());
	_moveTo = QPoint(pos.x(),pos.y());
	ItemSelect * line = new ItemSelect(_moveTo,_lineTo);
	line->setParent(this);
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
		setSelected(_item);
		_selected = list;
	}else setSelected(nullptr);
	removeItem(_line);
	_line = nullptr;
}

Association * UMLScene::_addAssociation(QPointF pos)
{
	_lineTo =QPoint(pos.x(),pos.y());
	_moveTo = QPoint(pos.x(),pos.y());
	Association * line = new Association(_moveTo,_lineTo);
	line->setParent(this);
	addItem(line);
	_line = line;
	return line;
}
Composition * UMLScene::_addComposition(QPointF pos)
{
	_lineTo =QPoint(pos.x(),pos.y());
	_moveTo = QPoint(pos.x(),pos.y());
	Composition * line = new Composition(_moveTo,_lineTo);
	line->setParent(this);
	addItem(line);
	_line = line;
	return line;
}
Generalization * UMLScene::_addGeneralization(QPointF pos)
{
	_lineTo =QPoint(pos.x(),pos.y());
	_moveTo = QPoint(pos.x(),pos.y());
	Generalization * line = new Generalization(_moveTo,_lineTo);
	line->setParent(this);
	addItem(line);
	_line = line;
	return line;
}