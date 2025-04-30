#include "PreferredTime.h"

PreferredTime::PreferredTime(const std::string& label)
	:StringField(label),
	m_optionsPreferredTime{"Morning","Noon", "Evening", "Night", "Don't Care" }
{
}

void PreferredTime::validat()
{
	m_isInputValid = false;

	for (int i = 0; i < m_optionsPreferredTime.size(); i++) {
		if (m_userInput == m_optionsPreferredTime[i]) {
			m_isInputValid = true;
			break;
		}
	}
}

void PreferredTime::printValidationError()
{
	if(!m_isInputValid)
		std::cout << "Error: Invalid preferred time selection. Please choose one of the listed options only." << std::endl;
}
