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
}

