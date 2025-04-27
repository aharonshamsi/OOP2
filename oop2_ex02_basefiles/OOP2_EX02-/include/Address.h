#pragma once
#include "NamesField.h"
#include "Name.h"

class Address : public NamesField {

public:
	Address(const std::string& label);

	void validat() override;
	void printValidationError() override;

private:
	Name m_street;
	Name m_numStreet;
	Name m_city;

	void splitAddress();
	void validNumStreet();

};
