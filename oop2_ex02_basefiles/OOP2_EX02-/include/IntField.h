#pragma once
#include "BaseField.h"

class IntField : public BaseField<int> {

public:
	IntField(const std::string& label, flightType type);

	void validator() override {};
	void print() override;


private:


};
