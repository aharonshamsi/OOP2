#include "HotelName.h"

HotelName::HotelName(const std::string& label)
	:StringField(label), m_name(label)
{}


void HotelName::validat()
{
	m_name.setUserInput(m_userInput);
	m_name.validat();

	if (!m_name.getInputValid())
		m_isInputValid = false;
}


