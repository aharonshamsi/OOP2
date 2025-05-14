#pragma once

#include <vector>
#include <iostream>
#include "MessageException.h"
#include "ManyArgumentsException.h"

inline constexpr int MAX_ALLOWED_VALUE = 1000;
inline constexpr int MIN_ALLOWED_VALUE = -1024;

template <typename T>
class SquareMatrix
{
public:
	SquareMatrix(const SquareMatrix&) = default;
	SquareMatrix(SquareMatrix&&) = default;
	SquareMatrix& operator=(const SquareMatrix&) = default;
	SquareMatrix& operator=(SquareMatrix&&) = default;
	~SquareMatrix() = default;
	//SquareMatrix(const std::vector<std::vector<T>>& matrix);
	//SquareMatrix(std::vector<std::vector<T>>&& matrix);
	SquareMatrix(int size, const T& value);
	SquareMatrix(int size);
	int size() const
	{
		return m_size;
	};
	T& operator()(int i, int j);
	const T& operator()(int i, int j) const;
	SquareMatrix& operator+=(const SquareMatrix& rhs);
	SquareMatrix& operator-=(const SquareMatrix& rhs);
	//SquareMatrix& operator*=(const SquareMatrix& rhs);
	//SquareMatrix& operator*=(const T& scalar);
	SquareMatrix operator+(const SquareMatrix& rhs) const;
	SquareMatrix operator-(const SquareMatrix& rhs) const;
	//SquareMatrix operator*(const SquareMatrix& rhs) const;
	SquareMatrix operator*(const T& scalar) const;
	//bool operator==(const SquareMatrix& rhs) const;
	//bool operator!=(const SquareMatrix& rhs) const;
	SquareMatrix Transpose() const;
	//void print(std::ostream& ostr) const;

	
private:
	int m_size;
	std::vector<std::vector<T>> m_matrix;
};

template <typename T>
const T& SquareMatrix<T>::operator()(int i, int j) const
{
	return m_matrix[i][j];
}

template <typename T>
T& SquareMatrix<T>::operator()(int i, int j)
{
	return m_matrix[i][j];
}

inline std::ostream& operator<<(std::ostream& ostr, const SquareMatrix<int>& matrix)
{
	for (int i = 0; i < matrix.size(); ++i)
	{
		for (int j = 0; j < matrix.size(); ++j)
		{
			ostr << matrix(i, j) << ' ';
		}
		ostr << '\n';
	}
	return ostr;
}

inline std::istream& readMatrix(std::istream& istr, SquareMatrix<int>& matrix, int& numLine)
{
	for (int i = 0; i < matrix.size(); ++i)
	{
		numLine++; // כל פעם שהתחלנו שורה חדשה במטריצה
		for (int j = 0; j < matrix.size(); ++j)
		{
			if (!(istr >> matrix(i, j))) {
				throw MessageException("Error: Invalid input. Please enter a valid number without extra characters.\n");
			}

			if (matrix(i, j) > MAX_ALLOWED_VALUE || matrix(i, j) < MIN_ALLOWED_VALUE) {
				throw MessageException(
					"Error: The entered number is not within the allowed range (" +
					std::to_string(MIN_ALLOWED_VALUE) + " to " + std::to_string(MAX_ALLOWED_VALUE) + ").\n");
			}
		}
	}

	std::string restOfLine;
	std::getline(istr, restOfLine);

	if (!restOfLine.empty() && restOfLine.find_first_not_of(" \t\r") != std::string::npos)
		throw ManyArgumentsException("Error: Too many arguments after operation index and size.\n");

	return istr;
}

// Implementation must be in .h file for the compiler to see it and instantiate
// the relevant function
template <typename T>
SquareMatrix<T>::SquareMatrix(int size, const T& value)
	: m_size(size), m_matrix(size, std::vector<T>(size, value))
{
	for (int i = 0; i < size * size; ++i)
	{
		m_matrix[i / size][i % size] = value;
	}
}

template <typename T>
SquareMatrix<T>::SquareMatrix(int size)
	: m_size(size), m_matrix(size, std::vector<T>(size))
{
	for (int i = 0; i < size * size; ++i)
	{
		m_matrix[i / size][i % size] = i;
	}
}

template <typename T>
SquareMatrix<T> SquareMatrix<T>::operator+(const SquareMatrix& rhs) const
{
	SquareMatrix result(*this);
	return result += rhs;
}


template <typename T>
SquareMatrix<T> SquareMatrix<T>::operator-(const SquareMatrix& rhs) const
{
	SquareMatrix result(*this);
	return result -= rhs;
}

template <typename T>
SquareMatrix<T>& SquareMatrix<T>::operator+=(const SquareMatrix& rhs)
{
	for (int i = 0; i < m_size; ++i)
	{
		for (int j = 0; j < m_size; ++j)
		{
			m_matrix[i][j] += rhs.m_matrix[i][j];
		}
	}
	return *this;
}

template <typename T>
SquareMatrix<T>& SquareMatrix<T>::operator-=(const SquareMatrix& rhs)
{
	for (int i = 0; i < m_size; ++i)
	{
		for (int j = 0; j < m_size; ++j)
		{
			m_matrix[i][j] -= rhs.m_matrix[i][j];
		}
	}
	return *this;
}

template <typename T>
SquareMatrix<T> SquareMatrix<T>::Transpose() const
{
	SquareMatrix result(m_size);
	for (int i = 0; i < m_size; ++i)
	{
		for (int j = 0; j < m_size; ++j)
		{
			result(i, j) = m_matrix[j][i];
		}
	}
	return result;
}


template <typename T>
SquareMatrix<T> SquareMatrix<T>::operator*(const T& scalar) const
{
	SquareMatrix result(*this);
	for (int i = 0; i < m_size; ++i)
	{
		for (int j = 0; j < m_size; ++j)
		{
			result(i, j) *= scalar;
		}
	}
	return result;
}