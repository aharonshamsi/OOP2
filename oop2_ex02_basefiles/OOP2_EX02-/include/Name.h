#pragma once
#include "NamesField.h"

class Name : public NamesField {

public:
	Name(const std::string& label);

	void validator() override {};

private:

};
