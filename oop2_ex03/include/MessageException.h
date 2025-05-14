#pragma once
#include "MatrixException.h"

class MessageException : public MatrixException {

public:
	MessageException(const std::string& message) : MatrixException(message) {}
};
