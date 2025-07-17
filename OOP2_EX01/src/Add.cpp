#include "Add.h"


Add::Add(const OperationTypes type, const std::shared_ptr<Operation> firstFunc, const std::shared_ptr<Operation> secondFunc)
	:Operation(type), m_firstFunction(firstFunc), m_secondFunction(secondFunc)
{}


void Add::evaluate(SquareMatrix& matrix)
{
	SquareMatrix secondMatrix(matrix.getSize(), true);
	
	m_firstFunction->evaluate(matrix);
	std::cout << " + ";
	m_secondFunction->evaluate(secondMatrix);

	matrix += secondMatrix;
}


void Add::print()
{
	m_firstFunction->print();
	std::cout << " + ";
	m_secondFunction->print();
}