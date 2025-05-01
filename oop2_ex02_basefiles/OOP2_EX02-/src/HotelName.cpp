#include "HotelName.h"

HotelName::HotelName(const std::string& label)
	:StringField(label), m_name(label)
{}


void HotelName::validat()
{
	m_name.setUserInput(m_userInput);
	m_name.validat();
}

std::string HotelName::getMessageError()
{
	m_isInputValid = m_name.getInputValid();

	if (!m_isInputValid)
		return "Error: The hotel name is invalid. Only alphabetic characters are allowed.\n";
	return "";
}
