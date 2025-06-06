#include "DepartureAirport.h"

DepartureAirport::DepartureAirport(const std::string& label)
	:StringField(label), m_departueAirport(label)
{}

void DepartureAirport::validat()
{
	m_departueAirport.setUserInput(m_userInput);
	m_departueAirport.validat(); 

	if (!m_departueAirport.getInputValid()) 
		m_isInputValid = false;
}

void DepartureAirport::reset()
{
	StringField::reset();
	m_departueAirport.reset();
}

