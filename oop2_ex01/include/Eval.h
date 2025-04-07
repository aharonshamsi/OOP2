#pragma once
#include "MatrixOperation.h"

class Eval : public MatrixOperation {
public:
    Eval() : MatrixOperation("id") {}
    void execute(std::shared_ptr<SquareMatrix> matrix) override;
};
