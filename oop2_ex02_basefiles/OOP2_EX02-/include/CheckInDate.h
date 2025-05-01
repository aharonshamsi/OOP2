#pragma once
#include "Date.h"

class CheckInDate : public Date {

public:
	CheckInDate(const std::string& label) : Date(label) {};

	std::string getMessageError() override {
		if (!m_isInputValid) {
			Date::defaultDate();
			return "Error: The check-in date is invalid. Please enter a valid date in the format YYYY-MM-DD.\n";
		}
		return "";
	};

};
