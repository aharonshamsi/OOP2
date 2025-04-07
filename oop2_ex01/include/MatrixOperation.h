#pragma once
#include "BaseOperation.h"
#include "SquareMatrix.h"

class MatrixOperation : public BaseOperation {
public:
    MatrixOperation(const std::string& name) : BaseOperation(name) {}
    virtual void execute(std::shared_ptr<SquareMatrix> matrix) override = 0;
};
