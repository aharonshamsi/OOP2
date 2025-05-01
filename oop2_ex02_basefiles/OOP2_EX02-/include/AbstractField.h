#pragma once

class AbstractField {

public:

	AbstractField(const std::string& label) : m_label(label), m_isInputValid(true) {}
	virtual ~AbstractField() = default;

	virtual void addChar(char ch) = 0;
	virtual void validat() = 0; // פונקציה ווירטואלית לבדיקת תקינות
	virtual std::string print() = 0;
	virtual std::string getMessageError() = 0; // ויטואלית טהורה להדפסת הודעות שגיאה
	virtual void reset() = 0;

	bool getInputValid() { return m_isInputValid; };
	std::string getLabel() const { return m_label; };
	void setIsInputValid(const bool other) { m_isInputValid = other; };
	
	virtual bool isEmpty() const = 0;
	virtual std::string getUserInputAsString() const = 0;
	virtual void setUserInput(const std::string& input) = 0;

protected:
	std::string m_label;
	bool m_isInputValid;

};
