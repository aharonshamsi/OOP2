#pragma once
#include "Date.h"

class CheckOutDate : public Date {

public:
	CheckOutDate(const std::string& label) : Date(label) {};

	void reset() override { 
		m_isInputValid = true; };

	std::string getMessageError() override
	{
		if (!m_isInputValid) {
			return "Out of range, YYYY-MM-DD format.\n";
		}
		return "";
	};

};
