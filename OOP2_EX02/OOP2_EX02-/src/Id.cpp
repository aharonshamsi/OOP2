#include "Id.h"
#include <algorithm>


Id::Id(const std::string& label)
	:IntField(label) 
{
    m_userInput = 0;
}


void Id::validat()
{
    std::string idStr = std::to_string(m_userInput); // ממיר למחרוזת

    if (!isLengthValid(idStr) || !isAllDigits(idStr) || m_userInput == 0 || !m_isInputValid) {
        m_isInputValid = false;
        return;
    }

    int total = sumIsraeliID(idStr);

    if (total % 10 == 0)
        m_isInputValid = true;
    else
        m_isInputValid = false;
}


std::string Id::getMessageError()
{
    if(!m_isInputValid)
        return "Wrong control digit.\n";
    return "";
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
