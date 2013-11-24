#include "UMLScene.h"


UMLScene::UMLScene(void) : 
	_items(std::list<UMLItem*>()) , _lines(std::list<UMLLine*>()) ,
	_line(nullptr)
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
	if(IsAddLineItem()){
		_addToScene(QPointF(event->scenePos().x(),event->scenePos().y()));
		setDrawState(UMLDrawToScene::DrawPress);
	}
	update();
	QGraphicsScene::mousePressEvent(event);
}
void UMLScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
	if(IsAddLineItem())
	{

		if(_line != nullptr){
			_lineTo = QPoint(event->scenePos().x(),event->scenePos().y());
			_line->setTargetPoint(_lineTo);
		}
		setDrawState(UMLDrawToScene::DrawMove);
	}
	update();
	QGraphicsScene::mouseMoveEvent(event);
}
void UMLScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
	if(IsAddLineItem()){
		if(_searchCanMatch(_line)==nullptr){
			removeItem(_line);
		}else{
			_lines.push_back(_line);
			_line = nullptr;
		}
		setDrawState(UMLDrawToScene::DrawFinish);
	}else
		if(_state != UMLAddToScene::None)
			_addToScene(event->scenePos());
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
	if(!min_point.isNull())
	{
		_item = setTo;
		(*line.*setter)(setTo);
	}
	return setTo;
}

UMLLine * UMLScene::_searchCanMatch(UMLLine * line)
{
	if(line==nullptr)return nullptr;
	_item = nullptr;
	if(_searchCanMatchItem(line,_moveTo,&UMLLine::setParentItem) == nullptr)return nullptr;
	if(_searchCanMatchItem(line,_lineTo,&UMLLine::setTargetItem) == nullptr)return nullptr;
	_item = nullptr;
	return line;
}
void UMLScene::_addToScene(QPointF pos)
{
	switch(_state){
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