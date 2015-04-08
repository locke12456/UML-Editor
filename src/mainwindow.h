#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <iostream>
#include <map>
#include <functional>
#include <QMainWindow>
#include <qsignalmapper.h>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <qinputdialog.h>
#include <UMLScene.h>


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
		void _actionSetItemName();
		
		void _actionSetGroup();
		void _actionSetUnGroup();
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
