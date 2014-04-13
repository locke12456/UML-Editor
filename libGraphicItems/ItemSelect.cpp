#include "ItemSelect.h"
#include "UMLScene.h"
using namespace std::placeholders; 
ItemSelect::ItemSelect(void) : UMLLine() , _list()
{
}

ItemSelect::ItemSelect(Port* p1,Port* p2) : UMLLine(p1,p2) , _list()
{
}

ItemSelect::~ItemSelect(void)
{
}
QPainterPath ItemSelect::shape(){   
	QPainterPath path;
	path.moveTo(getLine().p1());
	path.lineTo(getLine().p1().x(),getLine().p2().y());
	path.lineTo(getLine().p2());
	path.lineTo(getLine().p2().x(),getLine().p1().y());
	path.lineTo(getLine().p1());
	return path;  
} 
void ItemSelect::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){   
	Q_UNUSED(widget);   
	if(UMLScene::GetScene()->getState()->getSelected() != nullptr)return;
	QPainterPath temp;
	QPainterPath path = shape();
	painter->setPen(QPen(Qt::red,1,Qt::DotLine));   
	//painter->fillPath(path,Qt::red);
	painter->drawPath(path);
}
void ItemSelect::findInRange(std::list<UMLItem*> items)
{
	std::for_each(items.begin(),items.end(),std::bind(&ItemSelect::_inRange,this,_1));
}
void ItemSelect::releaseAll(std::list<UMLItem*> items)
{
	std::for_each(items.begin(),items.end(),std::bind(&ItemSelect::_release,this,_1));
}
void ItemSelect::selectAll(std::list<UMLItem*> items)
{
	std::for_each(items.begin(),items.end(),std::bind(&ItemSelect::_select,this,_1));
}
std::list<UMLItem *> ItemSelect::getSelectedItems(std::list<UMLItem*> items)
{
	_list = std::list<UMLItem*>();
	std::for_each(items.begin(),items.end(),std::bind(&ItemSelect::_getSelected,this,_1));
	return _list;
}
void ItemSelect::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
	UMLLine::mousePressEvent(event);
}
void ItemSelect::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
	UMLLine::mouseMoveEvent(event);
	if(_state != ItemState::Selected)return;
	setPos(event->scenePos().x(),event->scenePos().y());
}
void ItemSelect::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
	UMLLine::mouseReleaseEvent(event);
}
void ItemSelect::_getSelected(UMLItem* item)
{
	if(item->getState() == ItemState::Selected){
		//item->setPortOpen(true);
		_list.push_back(item);
	}//else
	//	item->setPortOpen(false);
}
void ItemSelect::_select(UMLItem* item)
{
	item->setState(ItemState::Selected);
}
void ItemSelect::_release(UMLItem* item)
{
	item->setState(ItemState::Normal);
}
void ItemSelect::_inRange(UMLItem* item)
{
	QRectF item_rect = item->sceneBoundingRect();
	QRectF rect = sceneBoundingRect();

	bool bound = (rect.x()<item_rect.x())&&(rect.y()<item_rect.y())&&
		((rect.x()+rect.width()>item_rect.x()+item_rect.width())
			&&(rect.y()+rect.height()>item_rect.y()+item_rect.height()));
	//qDebug()<< (QPointF(item_rect.x(),item_rect.y()) - QPointF(rect.x(),rect.y()));
	item->setState(bound?ItemState::Selected:ItemState::Normal);
}