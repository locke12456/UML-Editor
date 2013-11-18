#include "mainwindow.h"
#include "ui_umlediter.h"


MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow),
	_scene(new UMLScene) , _mapper(new QSignalMapper(this)) , _actions(new Actions) , _pre_action(nullptr)

{
	ui->setupUi(this);


	_initEvents();
	_mapAction();

	ui->painter->setScene(_scene);
	ui->painter->show();

	// a white semi-transparent foreground
	_scene->setBackgroundBrush(QColor(255, 255, 255, 127));

	// a grid foreground
	_scene->setBackgroundBrush(QBrush(Qt::lightGray, Qt::CrossPattern));

}

MainWindow::~MainWindow()
{
	delete _scene;
	delete _mapper;
	delete _actions;
	delete ui;
}

void MainWindow::_initEvents()
{
	_actions->insert(	std::make_pair(Select				,ui->actionSelect				)  );
	_actions->insert(	std::make_pair(Broom				,ui->actionBroom				)  );
	_actions->insert(	std::make_pair(Add_package			,ui->actionAdd_package			)  );
	_actions->insert(	std::make_pair(Add_class			,ui->actionAdd_class			)  );
	_actions->insert(	std::make_pair(Add_association		,ui->actionAdd_association		)  );
	_actions->insert(	std::make_pair(Add_aggregation		,ui->actionAdd_aggregation		)  );
	_actions->insert(	std::make_pair(Add_composition		,ui->actionAdd_composition		)  );
	_actions->insert(	std::make_pair(Add_association_end	,ui->actionAdd_association_end	)  );
	_actions->insert(	std::make_pair(Add_generalization	,ui->actionAdd_generalization	)  );
	_actions->insert(	std::make_pair(Add_interface		,ui->actionAdd_interface		)  );
	_actions->insert(	std::make_pair(Add_Realization		,ui->actionAdd_Realization		)  );
	_actions->insert(	std::make_pair(Add_dependency		,ui->actionAdd_dependency		)  );
	_actions->insert(	std::make_pair(Add_attribute		,ui->actionAdd_attribute		)  );
	_actions->insert(	std::make_pair(Add_operation		,ui->actionAdd_operation		)  );
	_actions->insert(	std::make_pair(Add_data_type		,ui->actionAdd_data_type		)  );
}
void MainWindow::_mapAction()
{
	connect( _mapper, SIGNAL( mapped( int ) ), SLOT( _actionTriggered( int ) ) );
	Actions::const_iterator it= _actions->begin();
	for(;it!=_actions->end();it++){
		_mapper->connect(		it->second	,SIGNAL(triggered()),SLOT(map()));
		_mapper->setMapping(	it->second	,it->first	);
	}
}																					
void MainWindow::_actionTriggered( int state ){
	_setState(UMLAddToScene(state));
}
void MainWindow::_setState(UMLAddToScene state){
	Actions::const_iterator action = _actions->find(state);
	if(action ==_actions->end())return;
	if(_pre_action!= nullptr)
		_pre_action->setChecked(false);
	QAction * qaction = action->second;
	_pre_action = qaction;
	_scene->setState(!qaction->isChecked()?UMLAddToScene::None:state);
}