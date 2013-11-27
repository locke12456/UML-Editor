#pragma once
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
#include <UMLBase.h>
#include <ItemSelect.h>
#include <Group.h>
#include <ClassItem.h>
#include <UseCaseItem.h>
#include <Association.h>
#include <Generalization.h>
#include <Composition.h>

class UMLScene :
	public QGraphicsScene , public UMLBase
{
public:
	UMLScene(void);
	~UMLScene(void);
	void setItemName();
	void setItemName(QString);
	void setGroup();
	void setUnGroup();
	void addClass();
	void addAssociation();
	virtual void moveTo(QPointF);
	void update_lines();
protected:
	virtual void mousePressEvent(QGraphicsSceneMouseEvent *event);
    virtual void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
private:
	typedef void (UMLLine::*_setter)(UMLItem*,int);

	QPoint _moveTo;
	QPoint _lineTo;
	Group * _group;
	UMLLine * _line;
	UMLItem * _item;

	std::list<UMLItem*> _items;
	std::list<UMLLine*> _lines;
	std::list<UMLItem*> _selected;
	UMLLine * _searchCanMatch(UMLLine *);
	UMLItem * _searchCanMatchItem(UMLLine *,QPoint ,_setter);

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

