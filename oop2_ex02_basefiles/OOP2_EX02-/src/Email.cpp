#include "Email.h"

Email::Email(const std::string& label)
	:StringField(label)
{
}


void Email::validat() {

    size_t atPos = m_userInput.find('@');
    size_t dotPos = m_userInput.rfind('.');

    if (atPos == std::string::npos || dotPos == std::string::npos || 
        dotPos + 2 >= m_userInput.size()) {
        m_isInputValid = false;
        return;
    }

    //Divides the input into three parts
    std::string userName = m_userInput.substr(0, atPos);
    std::string domain = m_userInput.substr(atPos + 1, dotPos - atPos - 1);
    std::string end = m_userInput.substr(dotPos + 1);

    if (userName.empty() || domain.empty() || end.size() < 2) {
        m_isInputValid = false;
        return;
    }

    if (!isValidCharEmail(userName) || !isValidCharEmail(domain) || !isValidCharEmail(end)) {
        m_isInputValid = false;
        return;
    }
}


bool Email::isValidCharEmail(const std::string& str)
{
    for (char c : str) {
        if (!std::isalnum(c) && c != '.' && c != '@' && c != '_' && c != '-') {
            return false;
        }
    }
    return true;
}
