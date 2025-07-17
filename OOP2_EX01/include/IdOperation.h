#pragma once
#include "Operation.h"


class IdOperation : public Operation
{
public:
	//constructor
	IdOperation(const OperationTypes type);

	//public functions
	void evaluate(SquareMatrix& matrix) override;
	void print() override;

private:
	//members


	//private functions

};