#include <iostream>
#include <vector>
#include <memory>
#include "SquareMatrix.h"
#include "Eval.h"
#include "Tran.h"
#include "Scal.h"
#include "Add.h"

void menuPrint(const std::vector<std::shared_ptr<BaseOperation>>& operations) {
    std::cout << "List of available matrix operations:\n";
    for (size_t i = 0; i < operations.size(); i++) {
        std::cout << i << ". " << operations[i]->getName() << std::endl;
    }
    std::cout << "Enter command ('help' for the list of available commands): ";
}

int main() {
    std::vector<std::shared_ptr<BaseOperation>> operations;

    // הוספת פעולות בסיסיות
    operations.push_back(std::make_shared<Eval>());
    operations.push_back(std::make_shared<Tran>());

    std::string operationName;

    while (true) {
        menuPrint(operations);
        std::cin >> operationName;

        if (operationName == "exit") break;

        else if (operationName == "scal") {
            int scalar;
            std::cin >> scalar;
            operations.push_back(std::make_shared<Scal>(scalar));
            continue;
        }

        else if (operationName == "add") {
            int op1, op2;
            std::cin >> op1 >> op2;
            if (op1 >= operations.size() || op2 >= operations.size()) {
                std::cout << "Invalid operation ID.\n";
                continue;
            }
            operations.push_back(std::make_shared<Add>(operations[op1], operations[op2]));
            continue;
        }

        int operationId;
        std::cin >> operationId;

        if (operationId >= operations.size()) {
            std::cout << "Invalid operation ID.\n";
            continue;
        }

        int size;
        std::cout << "Enter matrix size: ";
        std::cin >> size;

        auto matrix1 = std::make_shared<SquareMatrix>(size);
        auto matrix2 = std::make_shared<SquareMatrix>(size);

        // בדיקה אם הפעולה היא מסוג add
        if (dynamic_cast<Add*>(operations[operationId].get())) {
            std::cout << "Enter first " << size << "x" << size << " matrix:\n";
            for (int i = 0; i < size; ++i) {
                for (int j = 0; j < size; ++j) {
                    int value;
                    std::cin >> value;
                    matrix1->setValue(i, j, value);
                }
            }

            std::cout << "Enter second " << size << "x" << size << " matrix:\n";
            for (int i = 0; i < size; ++i) {
                for (int j = 0; j < size; ++j) {
                    int value;
                    std::cin >> value;
                    matrix2->setValue(i, j, value);
                }
            }

            std::cout << "Applying operations on first matrix...\n";
            auto addOperation = std::dynamic_pointer_cast<Add>(operations[operationId]);
            addOperation->getOp1()->execute(matrix1);

            std::cout << "Applying operations on second matrix...\n";
            addOperation->getOp2()->execute(matrix2);

            // חיבור המטריצות
            for (int i = 0; i < size; ++i) {
                for (int j = 0; j < size; ++j) {
                    int sum = matrix1->getMatrix(i, j) + matrix2->getMatrix(i, j);
                    matrix1->setValue(i, j, sum);
                }
            }
        }
        else {
            // פעולה רגילה - המשתמש מכניס רק מטריצה אחת
            std::cout << "Enter a " << size << "x" << size << " matrix:\n";
            for (int i = 0; i < size; ++i) {
                for (int j = 0; j < size; ++j) {
                    int value;
                    std::cin >> value;
                    matrix1->setValue(i, j, value);
                }
            }

            std::cout << "Applying operation " << operations[operationId]->getName() << "...\n";
            operations[operationId]->execute(matrix1);
        }

        //std::cout << "Resulting matrix:\n";
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                std::cout << matrix1->getMatrix(i, j) << " ";
            }
            std::cout << std::endl;
        }
    }

    return 0;
}
