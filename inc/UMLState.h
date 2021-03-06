#pragma once
#include <qpoint.h>
enum UMLAddToScene{
	None
	,SelectItemMode	
	,ReleaseItemMode
	,GroupItemMode
	,UnGroupItemMode
	,Broom						
	,Add_package			
	,Add_class			
	,Add_use_case
	,Add_interface	
	,Add_association		
	,Add_uni_association
	,Add_aggregation		
	,Add_composition		
	,Add_association_end	
	,Add_generalization		
	,Add_Realization		
	,Add_dependency		
	,Add_attribute		
	,Add_operation		
	,Add_data_type		
};
enum UMLDrawToScene{
	DrawNone,DrawPress,DrawMove,DrawFinish	
};
class UMLState
{
public:
	UMLState(void);
	~UMLState(void);
	UMLAddToScene getModeState();
	void setModeState(UMLAddToScene state);
	void * getSelected();
	void setSelected(void* selected);
	UMLDrawToScene getDrawState();
	void setDrawState(UMLDrawToScene state);

	bool IsItemSelect();
	bool IsAddLineItem();
	bool IsAddObjectItem();
	bool IsChangeItemInfo();
	bool IsDrawPress();
	bool IsDrawMove();
	bool IsDrawFinish();
protected:
	
	UMLAddToScene _state;
	UMLDrawToScene _draw;
	void * _selected;
};

