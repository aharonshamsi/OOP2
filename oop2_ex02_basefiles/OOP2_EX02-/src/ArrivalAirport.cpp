#include "ArrivalAirport.h"


ArrivalAirport::ArrivalAirport(const std::string& label)
	:StringField(label), m_arrivalAirport(label)
{
}


void ArrivalAirport::validat()
{
	m_arrivalAirport.setUserInput(m_userInput);
	m_arrivalAirport.validat();

	if (!m_arrivalAirport.getInputValid())
		m_isInputValid = false;
}


void ArrivalAirport::printValidationError()
{
	if(!m_isInputValid)
		std::cout << "Error: The arrival airport name is invalid. Only alphabetic characters are allowed." << std::endl;
}
