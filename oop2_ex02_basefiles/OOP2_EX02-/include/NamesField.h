#pragma once
#include "StringField.h"
#include "string"


class NamesField : public StringField {

public:
	NamesField(const std::string& label);

	void validator() override;
	void printValidationError() override;
};
