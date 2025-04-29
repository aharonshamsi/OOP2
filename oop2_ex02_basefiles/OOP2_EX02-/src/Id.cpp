#include "Id.h"
#include <algorithm>


Id::Id(const std::string& label)
	:IntField(label) 
{
    m_isInputValid = true;
}


void Id::validat()
{

    std::string idStr = std::to_string(m_userInput); // ממיר למחרוזת

    if (!isLengthValid(idStr) || !isAllDigits(idStr) || !m_isInputValid) {
        m_isInputValid = false;
        return;
    }

    int total = sumIsraeliID(idStr);

    if (total % 10 == 0)
        m_isInputValid = true;
    else
        m_isInputValid = false;

}


void Id::addChar(char ch)
{
    if (isdigit(ch)) {
        int digit = ch - '0';
        m_userInput = m_userInput * 10 + digit;
    }

    else
        m_isInputValid = false; 
    // נשאר לטפל אם שמתי גם תו, וקיבלתי הודעת שגיאה לחצי איקס לתקן זה לא באמת מוחק את הקלט
    std::cout << m_userInput;
}


void Id::printValidationError()
{
    if(!m_isInputValid)
        std::cout << "Error: The ID is invalid. Only numeric digits are allowed." << std::endl;
}


bool Id::isLengthValid(const std::string& id) const
{
    if (id.empty() || id.size() > 9) {
        return false;
    }
    return true;
}


bool Id::isAllDigits(const std::string& id) const
{
    if (!std::all_of(id.begin(), id.end(), ::isdigit)) {
        return false;
    }
    return true;
}


int Id::sumIsraeliID(const std::string& id)
{
    int total = 0;
    for (size_t i = 0; i < id.size(); i++) {
        int digit = id[i] - '0';
        int tempSum = (i % 2 == 0) ? digit : digit * 2;
        if (tempSum > 9)
            tempSum -= 9;
        total += tempSum;
    }
    return total;
}
