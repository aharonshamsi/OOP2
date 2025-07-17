#include "StringField.h"

StringField::StringField(const std::string& label)
	:BaseField(label) {}

void StringField::addChar(char ch)
{
	m_userInput += ch;
}

void StringField::reset()
{
	m_isInputValid = true;
}

void StringField::deleteLastChar()
{
	if (!m_userInput.empty())
		m_userInput.pop_back();
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


