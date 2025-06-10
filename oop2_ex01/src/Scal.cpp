#include "Scal.h"
#include <iostream>

Scal::Scal(int scalar) : BaseOperation("scal " + std::to_string(scalar)), m_scalar(scalar) {}

void Scal::execute(std::shared_ptr<SquareMatrix> matrix) {
    std::cout << getName() << "(\n";
    matrix->print();
    std::cout << "= )\n";

    for (int i = 0; i < matrix->getSize(); ++i) {
        for (int j = 0; j < matrix->getSize(); ++j) {
            matrix->setValue(i, j, matrix->getMatrix(i, j) * m_scalar);
        }
    }

    //matrix->print();
}
