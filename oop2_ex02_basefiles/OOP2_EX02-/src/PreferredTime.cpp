#include "PreferredTime.h"

PreferredTime::PreferredTime(const std::string& label)
	:StringField(label)
{
}

void PreferredTime::validat()
{
	// פה נבצע תקינות של השדה
}

void PreferredTime::printValidationError()
{
	// הודעה שגיאה מתאימה
}
