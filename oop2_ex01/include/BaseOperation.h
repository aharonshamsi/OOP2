#pragma once
#include <string>
#include <memory>
#include "SquareMatrix.h"

class BaseOperation {
public:

    BaseOperation(const std::string& name) : m_name(name) {}
    virtual ~BaseOperation() = default;
    virtual void execute(std::shared_ptr<SquareMatrix> matrix) = 0;
    std::string getName() const { return m_name; }

protected:
    std::string m_name;
};