#pragma once
#include "NamesField.h"

class Address : public NamesField {

public:
	Address(const std::string& label);

	void validator() override;

};
