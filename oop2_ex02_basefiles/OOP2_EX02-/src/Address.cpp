#include "Address.h"

Address::Address(const std::string& label)
	:NamesField(label), m_street(label), m_numStreet(label), m_city(label)
{}


void Address::validat()
{
	splitAddress();
	std::cout << m_userInput;

	m_street.validat(); // בידקה שם רחוב
	validNumStreet(); // בדיקה מספר
	m_city.validat(); // בידקה שם עיר
}


void Address::printValidationError()
{
	if (!m_isInputValid)
		std::cout << "Error: Invalid address format. Please enter a valid street, number, and city." << std::endl;
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

	std::string numStreet = m_numStreet.getUserInput();

	m_isInputValid = !numStreet.empty(); // כלומר אם לא ריק מקבל אמת

	for (char c : numStreet) {
		if (!isdigit(c)) {
			m_isInputValid = false;
			break;
		}
	}

}
