#include "SquareMatrix.h"
#include <iostream>

SquareMatrix::SquareMatrix(int size) : m_size(size) {
    m_matrix.resize(size, std::vector<int>(size));
}

void SquareMatrix::print() const {
    for (size_t i = 0; i < m_size; i++) {
        for (size_t j = 0; j < m_size; j++) {
            std::cout << m_matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void SquareMatrix::transpose() {
    for (int i = 0; i < m_size; ++i) {
        for (int j = i + 1; j < m_size; ++j) {
            std::swap(m_matrix[i][j], m_matrix[j][i]);
        }
    }
}

