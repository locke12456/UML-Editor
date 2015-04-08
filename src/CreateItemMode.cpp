#include "CreateItemMode.h"
#include "UMLScene.h"

CreateItemMode::CreateItemMode(void)
{
}
CreateItemMode::~CreateItemMode(void)
{
}
void  CreateItemMode::generate()
{
	UMLState* _state = UMLScene::GetScene()->getState();
	
	_state->setDrawState(UMLDrawToScene::DrawPress);
}
void  CreateItemMode::contact()
{
	UMLState* _state = UMLScene::GetScene()->getState();
	_state->setDrawState(UMLDrawToScene::DrawMove);
}
void  CreateItemMode::modify()
{
	UMLState* _state = UMLScene::GetScene()->getState();
	_state->setDrawState(UMLDrawToScene::DrawFinish);
}

CreateClass::CreateClass(void)
{
}
CreateClass::~CreateClass(void)
{
}
void  CreateClass::generate(){
	CreateItemMode::generate();
	QPointF pos = UMLScene::GetScene()->MousePosition();
	ClassItem *item = new ClassItem(100,80);
	item->setName("Class",16);
	item->setPos(pos);
	UMLScene::GetScene()->addItem(item);
	UMLScene::GetScene()->getItemList()->push_back(item);
}

CreateUseCase::CreateUseCase(void)
{
}
CreateUseCase::~CreateUseCase(void)
{
}
void  CreateUseCase::generate(){
	//return new UseCaseItem();
	CreateItemMode::generate();
	QPointF pos = UMLScene::GetScene()->MousePosition();
	UseCaseItem *item = new UseCaseItem(100,80);
	item->setName("UseCase",16);
	item->setPos(pos);
	UMLScene::GetScene()->addItem(item);
	UMLScene::GetScene()->getItemList()->push_back(item);
}

//SetNameMode::SetNameMode(void)
//{
//}
//SetNameMode::~SetNameMode(void)
//{
//}
//void SetNameMode::modify(){
//	/*
//	UMLItem *item = *(UMLScene::GetScene()->getSelected()->begin());
//	item->setName("UseClass",16);
//	UMLScene::GetScene()->addItem(item);
//	UMLScene::GetScene()->getItemList()->push_back(item);*/
//}