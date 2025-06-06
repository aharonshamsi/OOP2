#pragma once
#include "BaseField.h"

class StringField : public BaseField<std::string> {

public:
	StringField(const std::string& label);

	void addChar(char ch) override;
	void reset() override;
	void deleteLastChar() override;
	bool isEmpty() const override;
	std::string getMessageError() override;
	void setUserInput(const std::string& input) override { m_userInput = input; }
	std::string getUserInputAsString() const override { return m_userInput; }

private:

};
