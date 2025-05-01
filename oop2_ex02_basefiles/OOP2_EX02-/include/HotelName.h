#pragma once
#include "StringField.h"
#include "Name.h"

class HotelName : public StringField {

public:
	HotelName(const std::string& label);

	void validat()override;
	std::string getMessageError() override;

private:
	Name m_name;
};