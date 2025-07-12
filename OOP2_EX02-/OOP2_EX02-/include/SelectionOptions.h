#pragma once
#include "StringField.h"
#include "vector"

class SelectionOptions : public StringField {

public:
	SelectionOptions(const std::string& label);


	void validat() override;
	std::string getMessageError() override;

protected:
	std::vector<std::string> m_selectionOptions; 

};
