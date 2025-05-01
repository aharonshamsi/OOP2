#pragma once
#include "StringField.h"
#include <algorithm>


class Email : public StringField {

public:
	Email(const std::string& label);

	void validat() override;

private:
	bool isValidCharEmail(const std::string& str);
};
