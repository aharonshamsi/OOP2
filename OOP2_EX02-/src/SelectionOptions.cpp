#include "SelectionOptions.h"

SelectionOptions::SelectionOptions(const std::string& label)
	:StringField(label)
{}


void SelectionOptions::validat()
{
	m_isInputValid = false;

	for (int i = 0; i < m_selectionOptions.size(); i++) {
		if (m_userInput == m_selectionOptions[i]) {
			m_isInputValid = true;
			break;
		}
	}
}

std::string SelectionOptions::getMessageError()
{
	if (!m_isInputValid)
		return "Choose one of the listed options only.\n";
	return "";
}

