#pragma once
#include "BaseOperation.h"

class Scal : public BaseOperation {
public:
    Scal(int scalar);
    void execute(std::shared_ptr<SquareMatrix> matrix) override;

private:
    int m_scalar;
};

