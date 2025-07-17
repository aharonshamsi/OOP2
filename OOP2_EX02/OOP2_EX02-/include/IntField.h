#pragma once
#include "BaseField.h"

class IntField : public BaseField<int> {

public:
	IntField(const std::string& label);

	void addChar(char ch) override;
	void deleteLastChar() override;
	bool isEmpty() const override;
	void reset() override;

	virtual std::string getMessageError() const { return ""; }

	std::string getUserInputAsString() const override {
		return std::to_string(m_userInput);
	}

private:

};
