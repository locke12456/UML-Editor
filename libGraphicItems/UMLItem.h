#pragma once

#include <QTimer>
#include <QPainter>
#include <QRectF>
#include <QPainterPath>
#include <QGraphicsSceneHoverEvent>
#include <QGraphicsSceneMouseEvent>
#include <QCursor>
#include <QGraphicsItem>
#include <QPainter>
#include <QStyleOptionGraphicsItem>
#include <QStyle>
#include <UMLBase.h>
enum ItemState{
	Normal,Selected,Hover
};
class UMLItem :
	public QGraphicsItem
{
	//Q_OBJECT
public:
	UMLItem(void);
	UMLItem(qreal wid,qreal hgt);
	QRectF boundingRect()const;   
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) = 0;   
    virtual QPainterPath shape()const;  
	void setParent(UMLBase * parent);
	UMLBase * getParent();
protected :

	QRectF _rect()const;
	
    virtual void mousePressEvent(QGraphicsSceneMouseEvent *event);
    virtual void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
    virtual void hoverEnterEvent(QGraphicsSceneHoverEvent *event);
    virtual void hoverMoveEvent(QGraphicsSceneHoverEvent *event);
    virtual void hoverLeaveEvent(QGraphicsSceneHoverEvent *event);
	ItemState _state;
private:   
	UMLBase * _parent;
    qreal _width;   
    qreal _height;  
};

