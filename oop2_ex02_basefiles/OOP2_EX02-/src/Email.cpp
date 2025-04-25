#include "Email.h"

Email::Email(const std::string& label)
	:NamesField(label)
{
}

void Email::validator()
{
	// פה נבצע תקינות על אמייל
}

void Email::printValidationError()
{
	std::cout << "Error: The email address is invalid. Please enter a valid email format." << std::endl;
}
