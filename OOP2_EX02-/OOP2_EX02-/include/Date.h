#pragma once
#include <ctime>
#include <sstream>
#include <iomanip>
#include "StringField.h"

class Date : public StringField {

public:
	Date(const std::string& labal);
	Date() : StringField("") {}  // default


	void validat() override;
	std::string getMessageError() override;
	void reset() override;
	
	void splitDate(const std::string& date);
	bool operator<(const Date& other) const;


protected:
	std::string m_year;
	std::string m_month;
	std::string m_day;

	size_t m_firstDash;
	size_t m_secondDash;

	bool isOnlyDigit();
	void defaultDate();
};
