#include "NumberGuests.h"

NumberGuests::NumberGuests(const std::string& label)
	:IntField(label)
{
	m_userInput = 0;
}

void NumberGuests::validat()
{
	IntField::validat(); 

	if (m_isInputValid) {
		if (m_userInput < 1 || m_userInput > 15)
			m_isInputValid = false;
	}
}

std::string NumberGuests::getMessageError()
{
	if (!m_isInputValid)
		return "The number of guests between 1 and 15.\n";
	return "";
}


