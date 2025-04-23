#include "Name.h"

Name::Name(const std::string& label, flightType type)
	:StringField(label, flightType::Name)
{
}



void Name::validator()
{
	while (!m_isInputValid) {
		std::cin >> m_userInput;
		m_isInputValid = true;

		for (int i = 0; i < m_userInput.size(); i++) {
			char ch = m_userInput[i];
			if (!isalpha(ch)) {
				m_isInputValid = false;
				break;
			}
		}
	}
}

