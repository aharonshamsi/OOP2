#pragma once
#include <ctime>
#include <sstream>
#include <iomanip>
#include "StringField.h"

class Date : public StringField {

public:
	Date(const std::string& labal);

	void validat() override;
	std::string getMessageError() override;
	void reset() override;
	
	

protected:
	std::string m_year;
	std::string m_month;
	std::string m_day;

	size_t m_firstDash;
	size_t m_secondDash;

	void splitDate();
	bool isOnlyDigit();
	void defaultDate();
};
