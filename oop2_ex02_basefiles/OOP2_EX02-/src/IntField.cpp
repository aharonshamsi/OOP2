#include "IntField.h"

IntField::IntField(const std::string& label)
	:BaseField(label) 
{
	m_userInput = 0;
}

void IntField::reset()
{
	m_userInput = 0;
	m_isInputValid = true;
}

