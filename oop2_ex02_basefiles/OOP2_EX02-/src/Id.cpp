#include "Id.h"
#include <algorithm>


Id::Id(const std::string& label, flightType type)
	:StringField(label, type) {}

void Id::validator()
{
    while (!m_isInputValid) {
        int totalId = 0;
        std::cin >> m_userInput;

        if (!isLengthValid())
            continue;

        if (!isAllDigits())
            continue;
        
        totalId = sumIsraeliID();

        if (totalId % 10 == 0)
            m_isInputValid = true;
        else {
            std::cout << "The Israeli ID card is not valid\n";
            m_isInputValid = false;
        }
    }

}


bool Id::isLengthValid() const
{
    if (m_userInput.size() > 9 || m_userInput.empty()) {
        std::cout << "ID must be up to 9 digits\n";
        return false;
    }
    return true;
}


bool Id::isAllDigits() const
{

    if (!std::all_of(m_userInput.begin(), m_userInput.end(), ::isdigit)) { // זאת פונקציה מקבלת תחילה וסוף ותנאי שמספר 
        std::cout << "ID must contain digits only\n";
        return false;
    }
    return true;
}


int Id::sumIsraeliID()
{
    int total = 0;
    for (size_t i = 0; i < m_userInput.size(); i++) {
        int tempSum = 0;
        int digit = m_userInput[i] - '0'; // המרה למספר

        if (i % 2 == 0)
            tempSum = digit * 1;

        else if ((digit * 2) > 9)
            tempSum = ((digit * 2) / 10) + ((digit * 2) % 10);

        else
            tempSum = digit * 2;

        total += tempSum;
    }

    return total;
}
