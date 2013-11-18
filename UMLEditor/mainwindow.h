#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <qsignalmapper.h>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <UMLScene.h>
#include <iostream>
#include <map>
#include <functional>
//enum UI_QAction_State{
//	Select,	Broom,	
//	Add_package,	Add_class,	Add_association,	Add_aggregation,	Add_composition,
//	Add_association_end,	Add_generalization,	Add_interface,	Add_Realization,
//	Add_dependency,	Add_attribute,	Add_operation,	Add_data_type,
//};

namespace Ui {
	class MainWindow;
}

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	typedef std::map<UMLAddToScene , QAction*> Actions;
	explicit MainWindow(QWidget *parent = 0);
	~MainWindow();
	private slots:
		//void _map();
		void _actionTriggered( int );
private:

	Ui::MainWindow *ui;
	UMLScene * _scene;
	QSignalMapper * _mapper;
	Actions * _actions;	
	QAction * _pre_action;
	void _initEvents();
	void _mapAction();
	void _setState(UMLAddToScene);
};

#endif // MAINWINDOW_H
