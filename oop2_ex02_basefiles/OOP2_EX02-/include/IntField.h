#pragma once
#include "BaseField.h"

class IntField : public BaseField<int> {

public:
	IntField(const std::string& label);
	void addChar(char ch) override;
	void reset() override;

	void validat() override {};
	virtual std::string getMessageError() const { return ""; }


	bool isEmpty() const override;
	std::string getUserInputAsString() const override {
		return std::to_string(m_userInput);
	}

private:


};
