#pragma once
#include "NamesField.h"

class Email : public NamesField {

public:
	Email(const std::string& label);

	void validator() override;
	void printValidationError() override;
};
