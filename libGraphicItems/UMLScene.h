#pragma once
#include <iostream>
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
#include <ItemSelect.h>
#include <Group.h>
#include <ClassItem.h>
#include <UseCaseItem.h>
#include <Association.h>
#include <Generalization.h>
#include <Composition.h>
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
	UMLGroup * getGroup();
	std::list<UMLItem*> * getSelected();
	std::list<UMLItem*> * getItemList();
	std::list<UMLLine*> * getLineList();
	QPointF MousePosition();
	void ChangeCurrentMode(UMLAddToScene );
	UMLState* getState();
	void addClass();
	void addAssociation();
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

	Port * _moveTo;
	Port * _lineTo;
	UMLGroup * _group;
	UMLLine * _line;
	UMLItem * _item;

	std::list<UMLItem*> _items;
	std::list<UMLLine*> _lines;
	std::list<UMLItem*> _selected;

	void _addToGroup();
	void _addToScene(QPointF);
	void _mousePress(QPointF);
	void _mouseMove(QPointF);
	void _mouseRelease(QPointF);
	void _initSelect(QPointF);
	void _releaseSelect();
	ClassItem * _addClass(QPointF);
	UseCaseItem * _addUseCaseItem(QPointF);
	Association * _addAssociation(QPointF);
	Composition * _addComposition(QPointF);
	Generalization * _addGeneralization(QPointF);
	void _drawMoveTo( QPoint point);
	void _drawLineTo( QPoint point);

};

