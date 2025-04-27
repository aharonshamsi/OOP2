#include "Email.h"

Email::Email(const std::string& label)
	:NamesField(label)
{
}

void Email::validat()
{
	// פה נבצע תקינות על אמייל
}

void Email::printValidationError()
{
	std::cout << "Error: The email address is invalid. Please enter a valid email format." << std::endl;
}
