#include "Date.h"


Date::Date(const std::string& label)
	: StringField(label)
{
	//defaultDate(); // מאתחל לתאריך נוכחי דיפולט
}


void Date::validat()
{
	// פה נבצע בדיקת תקינות של תאריך
	if (!isOnlyDigit()) {
		m_isInputValid = false;
		return;
	}

	splitDate();

	if (m_firstDash != 4 || (m_secondDash != 7 && m_secondDash != 6) ||
		m_year.size() != 4 || (m_month.size() != 2 && m_month.size() != 1)
		|| (m_day.size() != 2 && m_day.size() != 1)) {
		m_isInputValid = false;
	}

}

std::string Date::getMessageError()
{
	if (!m_isInputValid) {
		defaultDate();
		return "Out of range, YYYY-MM-DD format.\n";
	}
	return "";
}


void Date::reset()
{
	Date::defaultDate();
	m_isInputValid = true;
}


void Date::splitDate()
{
	m_firstDash = m_userInput.find('-');
	m_secondDash = m_userInput.find('-', m_firstDash + 1);

	m_year = m_userInput.substr(0, m_firstDash);
	m_month = m_userInput.substr(m_firstDash + 1, m_secondDash - m_firstDash - 1);
	m_day = m_userInput.substr(m_secondDash + 1);
}


bool Date::isOnlyDigit()
{
	for (char c : m_userInput) {
		if (!isdigit(c) && c != '-') {
			return false;
		}
	}

	return true;
}


void Date::defaultDate()
{
	std::time_t now = std::time(nullptr);
	std::tm localTime;
	localtime_s(&localTime, &now);  // גרסה בטוחה יותר

	std::stringstream ss;
	ss << std::put_time(&localTime, "%Y-%m-%d");
	m_userInput = ss.str();
}
