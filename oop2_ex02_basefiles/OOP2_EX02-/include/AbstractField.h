#pragma once

class AbstractField {

public:

	AbstractField(const std::string& label) : m_label(label), m_isInputValid(false) {}

	virtual void addChar(char ch) = 0;
	virtual void validat() = 0; // פונקציה ווירטואלית לבדיקת תקינות
	virtual void print() = 0;
	virtual void printValidationError() = 0; // ויטואלית טהורה להדפסת הודעות שגיאה
	virtual void reset() = 0;

	bool getInputValid() { return m_isInputValid; };
	

protected:
	std::string m_label;
	bool m_isInputValid;

};
