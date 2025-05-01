#pragma once
#include "Date.h"

class CheckOutDate : public Date {

public:
	CheckOutDate(const std::string& label) : Date(label) {};

	std::string getMessageError() override {
		if (!m_isInputValid) {
			Date::defaultDate();
			return "Error: The check-out date is invalid. It must be after the check-in date and in the format YYYY-MM-DD.\n";
		}
		return "";
	};

};
