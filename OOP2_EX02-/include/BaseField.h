#pragma once
#include <iostream>
#include "AbstractField.h"
#include <sstream>


template <class T>
class BaseField : public AbstractField {

public:
	BaseField(const std::string& fiels);

	virtual void addChar(char ch) = 0;
	virtual void deleteLastChar() = 0;
	virtual bool isEmpty() const = 0;
	std::string print() override;
	void validat() override {};
	void reset() override {};

	virtual std::string getMessageError() const { return ""; }
	void setUserInput(const std::string& input) override {};

protected:
	T m_userInput;

};




template<class T>
inline BaseField<T>::BaseField(const std::string& label)
	:AbstractField(label)
{}


template<class T>
inline std::string BaseField<T>::print()
{
	std::stringstream ss;
	ss << m_label << " " << m_userInput;
	return ss.str();
}
