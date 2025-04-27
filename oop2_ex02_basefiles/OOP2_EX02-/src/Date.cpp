#include "Date.h"

Date::Date(const std::string& label)
	:StringField(label)

{
	// כאן צריך לאתחל תאריך דיפולטיבי להיום
	splitDate();
}


void Date::validat()
{
	// פה נבצע בדיקת תקינות של תאריך
	m_isInputValid = true;

	if (m_firstDash != 4 || m_secondDash != 7 ||
		m_year.size() != 4 || m_month.size() != 2 || m_day.size() != 2)
		m_isInputValid = false;

}


void Date::printValidationError()
{
	if(!m_isInputValid)
		std::cout << "Error: Invalid date format. Please enter a valid date in YYYY-MM-DD format." << std::endl;
}



void Date::splitDate()
{
	// פה נבצע את החלוקה
	m_firstDash = m_userInput.find('-');
	m_secondDash = m_userInput.find('-', m_firstDash + 1);

	m_year = m_userInput.substr(0, m_firstDash);
	m_month = m_userInput.substr(m_firstDash + 1, m_secondDash - m_firstDash - 1);
	m_day = m_userInput.substr(m_secondDash + 1);
}
