#pragma once
#include "qpainterpath.h"
#include <qfont.h>
#define DEFAULT_FONT "Arial"
class UMLTextItem 
{
public:
	UMLTextItem(void);
	void setText(std::string );
	std::string getText();
	void setFont(const QString &, int );
	QString getFont();
	QPainterPath getPath();
	void setPosition(int x,int y);
	QRectF getRect();
private:
	QPoint _point;
	QPainterPath _path;
	void _clear();
	std::string _text;
	QString _font;
	int _font_size;
};

