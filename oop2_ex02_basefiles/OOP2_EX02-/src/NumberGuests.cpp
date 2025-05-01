#include "NumberGuests.h"
#include "NumberGuests.h"
#include "NumberGuests.h"
#include "NumberGuests.h"

NumberGuests::NumberGuests(const std::string& label)
	:IntField(label)
{}

void NumberGuests::validat()
{
	IntField::validat(); // קריאה לבדיקה של האב

	if (m_isInputValid) {
		if (m_userInput < 1 || m_userInput > 15)
			m_isInputValid = false;
	}
}

std::string NumberGuests::getMessageError()
{
	if (!m_isInputValid)
		return "Error: The number of guests is invalid. It must be a numeric value between 1 and 15.\n";
	return "";
}


