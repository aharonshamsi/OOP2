#pragma once
#include "StringField.h"

class Name : public StringField {

public:
	Name(const std::string& label, flightType type);

	void validator() override;

private:

};
