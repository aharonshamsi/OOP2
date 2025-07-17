#include "Composite.h"


Composite::Composite(const OperationTypes type, const std::shared_ptr<Operation> firstFunc, const std::shared_ptr<Operation> secondFunc)
	:Operation(type), m_firstFunction(firstFunc), m_secondFunction(secondFunc)
{}


void Composite::evaluate(SquareMatrix& matrix)
{
	m_firstFunction->evaluate(matrix);
	std::cout << " -> ";
	m_secondFunction->evaluate(matrix);
}


void Composite::print()
{
	m_firstFunction->print();
	std::cout << " -> ";
	m_secondFunction->print();
}