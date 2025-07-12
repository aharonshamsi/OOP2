#pragma once
#include "NamesField.h"

class Name : public NamesField {

public:
	Name(const std::string& label) : NamesField(label) {};

	std::string getMessageError() override {
		if(!m_isInputValid)
			return "The input not adhere to the expected format.\n";
		return "";
	}

private:

};
