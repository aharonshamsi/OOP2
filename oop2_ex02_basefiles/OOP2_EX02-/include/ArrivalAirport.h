#pragma once
#include "StringField.h"
#include "Name.h"

class ArrivalAirport : public StringField {

public:
	ArrivalAirport(const std::string& label);

	void validat() override;


private:
	Name m_arrivalAirport;
};