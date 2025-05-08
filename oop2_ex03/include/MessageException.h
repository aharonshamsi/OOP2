#pragma once
#include "MatrixException.h"

class MessageException : public MatrixException {

public:
	MessageException(const std::string& message) : MatrixException(message) {}
	
	const char* what() const override {
		return m_errorMessage.c_str(); // מחזיר מצביע char לראש מחרוזת
	}

};
