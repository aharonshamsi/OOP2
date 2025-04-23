#pragma once
#include "StringField.h"

class Id : public StringField {

public:
	Id(const std::string& label, flightType type);

	void validator() override;


private:
	bool isLengthValid() const;
	bool isAllDigits() const;
	int sumIsraeliID();
};
