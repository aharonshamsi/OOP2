#include "NamesField.h"


NamesField::NamesField(const std::string& label)
	:StringField(label)
{
}

void NamesField::validat()
{
	m_isInputValid = true;

	if (m_userInput.empty()) {
		m_isInputValid = false;
		return;
	}

	for (int i = 0; i < m_userInput.size(); i++) {
		char ch = m_userInput[i];
		if (!isalpha(ch) && ch != ' ') {
			m_isInputValid = false;
			break;
		}
	}

}


