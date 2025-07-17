#pragma once
#include <vector>


class SquareMatrix
{
public:
	//constructor
	SquareMatrix();
	SquareMatrix(const int size, const bool input);

	//operators
	SquareMatrix& operator+=(const SquareMatrix& other) ;
	SquareMatrix& operator-=(const SquareMatrix& other) ;
	SquareMatrix& operator*=(const int scalar);

	//public functions
	int getIndex(const int i, const int j) const;
	void setIndex(const int i, const int j, const int val);
	int getSize() const;
	void print()const;
	void inputMatrix();
	void transpose();


private:
	//members
	int m_size;
	std::vector < std::vector<int> > m_matrix; 


	//private functions
	

};