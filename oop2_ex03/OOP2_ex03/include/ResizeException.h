#pragma once
#include "MatrixException.h"

class ResizeException : public MatrixException {

public:
	ResizeException(const std::string& message) : MatrixException(message) {};
};
