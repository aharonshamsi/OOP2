#pragma once
#include "MatrixOperation.h"

class Tran : public MatrixOperation {
public:
    Tran() : MatrixOperation("tran") {}
    void execute(std::shared_ptr<SquareMatrix> matrix) override;
};
