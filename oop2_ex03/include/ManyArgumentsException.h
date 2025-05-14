#pragma once
#include "MatrixException.h"

class ManyArgumentsException : public MatrixException {

public:
	ManyArgumentsException(const std::string& message) : MatrixException(message) {};
};
