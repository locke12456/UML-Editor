#include "UMLScene.h"


UMLScene::UMLScene(void) : 
	_class(std::list<ClassItem*>()) 
{
}


UMLScene::~UMLScene(void)
{
	while(_class.size()>0){
		std::list<ClassItem*>::iterator it = _class.begin();
		ClassItem *item = *it;
		removeItem(item);
		_class.pop_back();
	}
}

void UMLScene::addClass(){
	_state = UMLAddToScene::Add_class;
}


void UMLScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
	update();
	QGraphicsScene::mousePressEvent(event);
}
void UMLScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
	update();
	QGraphicsScene::mouseMoveEvent(event);
}
void UMLScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
	if(_state != UMLAddToScene::None)
		_addToScene(event->scenePos());
	update();
	QGraphicsScene::mouseMoveEvent(event);
}

void UMLScene::_addToScene(QPointF pos)
{
	switch(_state){
	case UMLAddToScene::Add_class:
		_class.push_back(_addClass(pos));
	}
}
ClassItem * UMLScene::_addClass(QPointF pos)
{
	ClassItem *item = new ClassItem(100,140);
	item->setClassName("Class",16);
	item->setPos(pos);
	item->setParent(this);
	addItem(item);
	return item;
}