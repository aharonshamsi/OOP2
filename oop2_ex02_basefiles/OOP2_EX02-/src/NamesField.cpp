#include "NamesField.h"


NamesField::NamesField(const std::string& label)
	:StringField(label)
{
}

void NamesField::validator()
{
	m_isInputValid = true;

	for (int i = 0; i < m_userInput.size(); i++) {
		char ch = m_userInput[i];
		if (!isalpha(ch)) {
			m_isInputValid = false;
			break;
		}
	}

}

void NamesField::printValidationError()
{
	if (!m_isInputValid)
		std::cout << "Error: The name is invalid. Only alphabetic characters are allowed" << std::endl;
}
