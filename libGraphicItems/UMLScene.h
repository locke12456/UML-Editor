#pragma once
#include <iostream>

#include <map>
#include <functional>
#include <list>
#include <QTimer>
#include <QPainter>
#include <QRectF>
#include <QPainterPath>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsSceneHoverEvent>
#include <QCursor>
#include <QGraphicsItem>
#include <QPainter>
#include <QStyleOptionGraphicsItem>
#include <QStyle>
#include <QGraphicsScene>
#include <QDebug>
#include <UMLState.h>
#include <Group.h>
#include <CreateItemMode.h>
#include <CreateLineMode.h>
#include <GroupMode.h>
#include <SelectMode.h>
class UMLScene :
	public QGraphicsScene
{
public:
	static UMLScene * GetScene();
	static void Destory();
	void setItemName();
	void setItemName(QString);
	void setGroup(UMLGroup *);
	UMLGroup * getGroup();
	void setSelected(std::list<UMLItem*> *);
	std::list<UMLItem*> * getSelected();
	std::list<UMLItem*> * getItemList();
	std::list<UMLLine*> * getLineList();
	QPointF MousePosition();
	void ChangeCurrentMode(UMLAddToScene );
	Mode * GetCurrentMode();
	UMLState* getState();
	bool IsSelected(UMLItem*);
protected:
	virtual void mousePressEvent(QGraphicsSceneMouseEvent *event);
    virtual void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
private:
	typedef std::map<UMLAddToScene , Mode*> Actions;
	typedef void (UMLLine::*_setter)(Port*);

	static UMLScene * _singleton;
	
	UMLScene(void);
	~UMLScene(void);

	void _init();
	void _changeCurrentMode(UMLAddToScene );

	Actions _modes;
	Mode * _currentMode;
	UMLState _state;
	QPointF _pos;
	UMLGroup * _group;
	
	std::list<UMLItem*> _items;
	std::list<UMLLine*> _lines;
	std::list<UMLItem*> _selected;

};

