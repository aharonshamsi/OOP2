#include "Sub.h"


Sub::Sub(const OperationTypes type, const std::shared_ptr<Operation> firstFunc, const std::shared_ptr<Operation> secondFunc)
	:Operation(type), m_firstFunction(firstFunc), m_secondFunction(secondFunc)
{}


void Sub::evaluate(SquareMatrix& matrix)
{
	SquareMatrix secondMatrix(matrix.getSize(), true);

	m_firstFunction->evaluate(matrix);
	std::cout << " - ";
	m_secondFunction->evaluate(secondMatrix);

	matrix -= secondMatrix;
}


void Sub::print()
{
	m_firstFunction->print();
	std::cout << " - ";
	m_secondFunction->print();
}