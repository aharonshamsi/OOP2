#pragma once
#include "StringField.h"
#include "string"
 

class NamesField : public StringField {

public:
	NamesField(const std::string& label);

	void validat() override;
	virtual std::string getMessageError() const { return ""; }

};
