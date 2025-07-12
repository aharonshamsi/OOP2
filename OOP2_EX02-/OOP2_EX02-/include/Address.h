#pragma once
#include "StringField.h"
#include "Name.h"

class Address : public StringField {

public:
	Address(const std::string& label);

	void validat() override;
	void reset() override;

private:
	Name m_street;
	Name m_numStreet;
	Name m_city;

	void splitAddress();
	void validNumStreet();
};
