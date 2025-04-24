#pragma once

class AbstractField {

public:

	AbstractField(const std::string& label) : m_label(label){}

	virtual void validator() = 0; // פונקציה ווירטואלית לבדיקת תקינות
	virtual void input() = 0;
	virtual void print() = 0;
	//virtual void printValidationError() = 0; // ויטואלית טהורה להדפסת הודעות שגיאה


protected:
	
	std::string m_label;

};
