#pragma once
#include "IntField.h"
#include <string>


class Id : public IntField {

public:
	Id(const std::string& label);

	void validat() override;
	std::string getMessageError() override;


private:
	bool isLengthValid(const std::string& id) const;
	bool isAllDigits(const std::string& id) const;
	int sumIsraeliID(const std::string& id);
};
