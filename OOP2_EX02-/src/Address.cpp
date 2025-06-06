#include "Address.h"

Address::Address(const std::string& label)
	:StringField(label), m_street(label), m_numStreet(label), m_city(label)
{}

void Address::validat()
{
	splitAddress(); // Street division, city number
	m_street.validat(); 
	validNumStreet(); 
	m_city.validat(); 

	if (!m_street.getInputValid() || !m_numStreet.getInputValid() || !m_city.getInputValid())
		m_isInputValid = false;
}

void Address::reset()
{
	StringField::reset();
	m_street.reset();
	m_numStreet.reset();
	m_city.reset();
}


void Address::splitAddress()
{
	size_t firstDash = m_userInput.find('-');
	size_t secondDash = m_userInput.find('-', firstDash + 1);

	m_street.setUserInput(m_userInput.substr(0, firstDash));
	m_numStreet.setUserInput(m_userInput.substr(firstDash + 1, secondDash - firstDash - 1));
	m_city.setUserInput(m_userInput.substr(secondDash + 1));

}


void Address::validNumStreet()
{
	std::string numStreet = m_numStreet.getUserInputAsString();

	m_isInputValid = !numStreet.empty(); 
	
	for (char c : numStreet) {
		if (!isdigit(c)) {
			m_numStreet.setIsInputValid(false);
			return;
		}
	}
}
