#include "Date.h"


Date::Date(const std::string& label)
	: StringField(label)
{
}


void Date::validat()
{
	if (!isOnlyDigit()) {
		m_isInputValid = false;
		return;
	}

	splitDate(m_userInput);

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
	m_isInputValid = true;
}

void Date::splitDate(const std::string& date)
{
	m_firstDash = date.find('-');
	m_secondDash = date.find('-', m_firstDash + 1);

	m_year = date.substr(0, m_firstDash);
	m_month = date.substr(m_firstDash + 1, m_secondDash - m_firstDash - 1);
	m_day = date.substr(m_secondDash + 1);
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

// מימוש אופרטור לבדיקת קדימות תאריך
bool Date::operator<(const Date& other) const {
	int yearL = std::stoi(m_year);
	int monthL = std::stoi(m_month);
	int dayL = std::stoi(m_day);

	int yearR = std::stoi(other.m_year);
	int monthR = std::stoi(other.m_month);
	int dayR = std::stoi(other.m_day);

	if (yearL != yearR) return yearL < yearR;
	if (monthL != monthR) return monthL < monthR;
	return dayL < dayR;
}