#include "Scalar.h"


Scalar::Scalar(const OperationTypes type)
	:Operation(type)
{
	std::cin >> m_scalarNum;
}


void Scalar::evaluate(SquareMatrix& matrix)
{
	std::cout << OperationNames::SCALAR << ' ' << m_scalarNum << " (\n";
	matrix.print();
	std::cout << ')';
	matrix *= m_scalarNum;
}


void Scalar::print()
{
	std::cout << OperationNames::SCALAR << ' ' << m_scalarNum;
}