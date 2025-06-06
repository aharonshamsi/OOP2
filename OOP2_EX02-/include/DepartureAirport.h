#pragma once
#include "StringField.h"
#include "Name.h"


class DepartureAirport : public StringField { 

public:
	DepartureAirport(const std::string& label);

	void validat() override;
	void reset() override;

private:
	Name m_departueAirport;
};
