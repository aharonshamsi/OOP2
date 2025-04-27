#pragma once
#include "StringField.h"

class Date : public StringField {

public:
	Date(const std::string& labal);

	void validat() override;
	void printValidationError() override;

private:
	std::string m_year;
	std::string m_month;
	std::string m_day;

	size_t m_firstDash;
	size_t m_secondDash;

	void splitDate();
};
