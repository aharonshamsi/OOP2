#pragma once
#include <vector>
#include <memory>
#include <iostream>
#include "Operation.h"
#include "IdOperation.h"
#include "Transpose.h"
#include "Scalar.h"
#include "Add.h"
#include "Sub.h"
#include "Composite.h"
#include "OperationTypes.h"
#include "OperationNames.h"
#include "OutputConsts.h"


class FunctionManager
{
public:
	//constructor
	FunctionManager();


	//public functions
	void runCalculator();


private:
	//members
	std::vector < std::shared_ptr <Operation> > m_functions;


	//private functions
	void printAll();
	OperationTypes inputManager(const std::string& input);
	void manageChoice(const OperationTypes option);

};