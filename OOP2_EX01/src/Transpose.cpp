#include "Transpose.h"


Transpose::Transpose(const OperationTypes type)
	:Operation(type)
{}



void Transpose::evaluate(SquareMatrix& matrix)
{
	std::cout << OperationNames::TRANSPOSE << " (\n";
	matrix.print();
	std::cout << ')';
	matrix.transpose();
}


void Transpose::print()
{
	std::cout << OperationNames::TRANSPOSE;
}