#include "StringField.h"

StringField::StringField(const std::string& label)
	:BaseField(label) {}

void StringField::addChar(char ch)
{
	m_userInput += ch;
	std::cout << m_userInput;
}

void StringField::reset()
{
	m_userInput = "";
	m_isInputValid = true;
}

std::string StringField::getMessageError()
{
	if (!m_isInputValid)
		return "The input not adhere to the expected format.\n";
	return "";
}

bool StringField::isEmpty() const
{
	return m_userInput.empty();
}


