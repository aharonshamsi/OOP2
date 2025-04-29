#pragma once
#include "NamesField.h"

class Name : public NamesField {

public:
	Name(const std::string& label) : NamesField(label) {};

	void printValidationError() override {
		if(!m_isInputValid)
			std::cout << "Error: The name is invalid. Only alphabetic characters are allowed." << std::endl;
	}

private:

};
