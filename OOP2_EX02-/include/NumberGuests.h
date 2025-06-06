#pragma once
#include "IntField.h"

class NumberGuests : public IntField {

public:
	NumberGuests(const std::string& label);

	void validat() override;
	std::string getMessageError() override;

};