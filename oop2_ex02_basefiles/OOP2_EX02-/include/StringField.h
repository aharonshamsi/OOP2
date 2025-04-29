#pragma once
#include "BaseField.h"

class StringField : public BaseField<std::string> {

public:

	StringField(const std::string& label);
	void addChar(char ch) override;
	void reset() override;

	void validat() override {};
	void printValidationError() override {};

private:

};
