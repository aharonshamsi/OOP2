#include "Eval.h"
#include <iostream>

void Eval::execute(std::shared_ptr<SquareMatrix> matrix) {
    // הדפסת המטריצה כפי שהיא (id - לא משנה את המטריצה)
    std::cout << "id(" << std::endl;
    matrix->print();
    std::cout << ") = " << std::endl;
}
