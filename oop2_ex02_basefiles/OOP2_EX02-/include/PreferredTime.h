#pragma once
#include "StringField.h"
#include "vector"

class PreferredTime : public StringField {

public:
	PreferredTime(const std::string& label);


	void validat() override;
	void printValidationError() override;

private:
	std::vector<std::string> m_optionsPreferredTime; // שדות של בחירה אפשרויות

};
