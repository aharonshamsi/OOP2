#include "IntField.h"

IntField::IntField(const std::string& label)
	:BaseField(label) 
{}


void IntField::addChar(char ch)
{
    if (isdigit(ch)) {
        int digit = ch - '0';
        m_userInput = m_userInput * 10 + digit;
    }

    else
        m_isInputValid = false;
}


void IntField::reset()
{
	m_isInputValid = true;
}


void IntField::deleteLastChar()
{
    m_userInput = m_userInput / 10;
}


bool IntField::isEmpty() const
{
    return m_userInput == 0;
}

