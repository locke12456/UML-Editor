#pragma once
enum UMLAddToScene{
	None
	,Select			
	,Broom						
	,Add_package			
	,Add_class			
	,Add_association		
	,Add_aggregation		
	,Add_composition		
	,Add_association_end	
	,Add_generalization	
	,Add_interface		
	,Add_Realization		
	,Add_dependency		
	,Add_attribute		
	,Add_operation		
	,Add_data_type		
};
class UMLBase
{
public:
	UMLBase(void);
	~UMLBase(void);
	UMLAddToScene getState();
	void setState(UMLAddToScene state);
protected:

	UMLAddToScene _state;
};

