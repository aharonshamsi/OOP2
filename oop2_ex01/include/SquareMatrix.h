#pragma once
#include <vector>
#include <iostream>

class SquareMatrix {
public:
    SquareMatrix(int size = 2);

    int getSize() const { return m_size; }
    int getMatrix(int i, int j) const { return m_matrix[i][j]; }
    void setValue(int i, int j, int value) { m_matrix[i][j] = value; }
    void print() const;
    void transpose();

private:
    int m_size;
    std::vector<std::vector<int>> m_matrix;
};
