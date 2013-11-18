#include "UMLTextItem.h"


UMLTextItem::UMLTextItem(void) :
	_point(),
	_text(),_font(DEFAULT_FONT),_font_size(12)
{

}
void UMLTextItem::setPosition(int x,int y){
	_clear();
	_point = QPoint(x,y);
	_path.addText(_point,QFont(_font,_font_size),QString(_text.c_str()));
}
QRectF UMLTextItem::getRect(){
	return _path.boundingRect();
}
QPainterPath UMLTextItem::getPath()
{
	return _path;
}
void UMLTextItem::setText(std::string text)
{
	_clear();
	_text = text;
	_path.addText(_point,QFont(_font,_font_size),QString(_text.c_str()));
}
std::string UMLTextItem::getText(){
	return _text;
}
void UMLTextItem::setFont(const QString & family, int pointSize )
{
	_clear();
	_font = family;
	_font_size = pointSize;
	_path.addText(_path.boundingRect().x(),_path.boundingRect().y(),QFont(_font,_font_size),QString(_text.c_str()));
}
QString UMLTextItem::getFont(){
	return _font;
}

void UMLTextItem::_clear()
{
	_path = QPainterPath();
}