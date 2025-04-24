#pragma once
#include "BaseField.h"

class IntField : public BaseField<int> {

public:
	IntField(const std::string& label);

	void validator() override {};

private:


};
