#pragma once
#include "Operation.h"


class Transpose : public Operation
{
public:
	//constructor
	Transpose(const OperationTypes type);

	//public functions
	void evaluate(SquareMatrix& matrix) override;
	void print() override;

private:
	//members


	//private functions

};