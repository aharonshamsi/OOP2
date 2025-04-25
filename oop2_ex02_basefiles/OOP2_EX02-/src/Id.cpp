#include "Id.h"
#include <algorithm>


Id::Id(const std::string& label)
	:IntField(label) {}

void Id::validator()
{

    std::string idStr = std::to_string(m_userInput); // ממיר למחרוזת

    if (!isLengthValid(idStr))
        m_isInputValid = false;

    if (!isAllDigits(idStr)) 
        m_isInputValid = false;

    int total = sumIsraeliID(idStr);

    if (total % 10 == 0)
        m_isInputValid = true;
    else {
        std::cout << "The Israeli ID card is not valid\n";
        m_isInputValid = false;
    }

}

void Id::printValidationError()
{
    if(!m_isInputValid)
        std::cout << "Error: The name is invalid. Only numbers are allowed." << std::endl;
}


bool Id::isLengthValid(const std::string& id) const
{
    if (id.empty() || id.size() > 9) {
        std::cout << "ID must be up to 9 digits\n";
        return false;
    }
    return true;
}


bool Id::isAllDigits(const std::string& id) const
{
    if (!std::all_of(id.begin(), id.end(), ::isdigit)) {
        std::cout << "ID must contain digits only\n";
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
