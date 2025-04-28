#pragma once
#include "BaseField.h"

class IntField : public BaseField<int> {

public:
	IntField(const std::string& label);
	void addChar(char ch) override {};

	void validat() override {};
	void printValidationError() override {};

private:


};
