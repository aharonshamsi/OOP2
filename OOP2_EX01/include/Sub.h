#pragma once
#include "Operation.h"
#include <memory>


class Sub : public Operation
{
public:
	//constructor
	Sub(const OperationTypes type, const std::shared_ptr<Operation> firstFunc, const std::shared_ptr<Operation> secondFunc);

	//public functions
	void evaluate(SquareMatrix& matrix) override;
	void print() override;

private:
	//members
	std::shared_ptr<Operation> m_firstFunction;
	std::shared_ptr<Operation> m_secondFunction;

	//private functions

};