#pragma once
#include "BaseField.h"

class StringField : public BaseField<std::string> {

public:

	StringField(const std::string& label, flightType type);

	void validator() override {};
	void print() override;

private:

};
