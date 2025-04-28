#pragma once
#include "StringField.h"

class PreferredTime : public StringField {

public:
	PreferredTime(const std::string& label);


	void validat() override;
	void printValidationError() override;

private:
};
