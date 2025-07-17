#include "IdOperation.h"


IdOperation::IdOperation(const OperationTypes type)
	:Operation(type)
{}


void IdOperation::evaluate(SquareMatrix& matrix)
{
	std::cout << OperationNames::ID << " (\n";
	matrix.print();
	std::cout << ')';
}


void IdOperation::print() 
{
	std::cout << OperationNames::ID;
}