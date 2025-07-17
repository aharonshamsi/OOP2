#include "SquareMatrix.h"
#include <iostream>

//================================ constructor ======================================

SquareMatrix::SquareMatrix()
{
	std::cin >> m_size;
	m_matrix.resize(m_size);
	for (int i = 0; i < m_size; i++)
		m_matrix[i].resize(m_size);

	inputMatrix();
}

SquareMatrix::SquareMatrix(const int size, const bool input)
	:m_size(size)
{
	m_matrix.resize(m_size);
	for (int i = 0; i < m_size; i++)
		m_matrix[i].resize(m_size);
	
	if (input)
		inputMatrix();
}

//================================ operators ======================================

SquareMatrix& SquareMatrix::operator+=(const SquareMatrix& other) 
{
	for (int i = 0; i < m_size; i++)
		for (int j = 0; j < m_size; j++)
			m_matrix[i][j] += other.getIndex(i, j);
	return *this;
}

SquareMatrix& SquareMatrix::operator-=(const SquareMatrix& other) 
{
	for (int i = 0; i < m_size; i++)
		for (int j = 0; j < m_size; j++)
			m_matrix[i][j] -= other.getIndex(i, j);
	return *this;
}

SquareMatrix& SquareMatrix::operator*=(const int scalar)
{
	for (int i = 0; i < m_size; i++)
		for (int j = 0; j < m_size; j++)
			m_matrix[i][j] *= scalar;
	return *this;
}


//================================ operators ======================================

int SquareMatrix::getIndex(const int i, const int j) const
{
	return m_matrix[i][j];
}

void SquareMatrix::setIndex(const int i, const int j, const int val)
{
	m_matrix[i][j] = val;
}

int SquareMatrix::getSize() const
{
	return m_size;
}

void SquareMatrix::print() const
{
	for (int i = 0; i < m_size; i++)
	{
		for (int j = 0; j < m_size; j++)
			std::cout << m_matrix[i][j] << ' ';
		std::cout << std::endl;
	}
}


void SquareMatrix::inputMatrix()
{
	int val;
	for (int i = 0; i < m_size; i++)
		for (int j = 0; j < m_size; j++)
		{
			std::cin >> val;
			m_matrix[i][j] = val;
		}
}

void SquareMatrix::transpose()
{
	int temp;
	for (int i = 0; i < m_size; i++)
		for (int j = i + 1; j < m_size; j++)
		{
			temp = m_matrix[i][j];
			m_matrix[i][j] = m_matrix[j][i];
			m_matrix[j][i] = temp;
		}
}