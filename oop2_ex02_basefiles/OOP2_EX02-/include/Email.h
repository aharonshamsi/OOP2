#pragma once
#include "NamesField.h"

class Email : public NamesField {

public:
	Email(const std::string& label);

	void validat() override;
	void printValidationError() override;
};
