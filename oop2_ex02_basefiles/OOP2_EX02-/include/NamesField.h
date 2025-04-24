#pragma once
#include "StringField.h"

class NamesField : public StringField {

public:
	NamesField(const std::string& label);

	void validator() override;
};
