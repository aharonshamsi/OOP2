#include "Tran.h"
#include <iostream>

void Tran::execute(std::shared_ptr<SquareMatrix> matrix) {
    // ביצוע טרנספוז למטריצה
    std::cout << "tran(" << std::endl;
    matrix->print();
    matrix->transpose(); // נניח שזו פונקציה שמבצעת טרנספוז
    std::cout << ") = " << std::endl;
}
