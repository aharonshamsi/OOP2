#pragma once
#include "Operation.h"


class Scalar : public Operation
{
public:
	//constructor
	Scalar(const OperationTypes type);

	//public functions
	void evaluate(SquareMatrix& matrix) override;
	void print() override;

private:
	//members
	int m_scalarNum;


	//private functions

};