#include "Address.h"

Address::Address(const std::string& label)
	:NamesField(label), m_street(label), m_numStreet(label), m_city(label)
{
	splitAddress();
}


void Address::validator()
{
	m_street.validator(); // בידקה שם רחוב
	validNumStreet(); // בדיקה מספר
	m_city.validator(); // בידקה שם עיר
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
	try {
		int numStreet = std::stoi(m_numStreet.getUserInput()); // נבדוק האם ההמרה למספר הצליחה
		m_isInputValid = numStreet > 0;
	}
	catch (const std::exception&) {
		m_isInputValid = false;
	}
}
