#pragma once
#include <string>
#include "SquareMatrix.h"
#include <iostream>
#include "OperationTypes.h"
#include "OperationNames.h"


class Operation
{
public:
	//constructor
	Operation(const OperationTypes type);

	//destructor
	virtual ~Operation() = default;

	//public functions
	virtual void evaluate(SquareMatrix& matrix) = 0;
	virtual void print() = 0;


private:
	//members
	OperationTypes m_type;
	


	//private functions

};