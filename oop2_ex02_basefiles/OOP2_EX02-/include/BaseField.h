#pragma once
#include <iostream>
#include "AbstractField.h"

template <class T>
class BaseField : public AbstractField {

public:
	BaseField(const std::string& fiels);

	virtual void addChar(char ch) = 0;
	virtual void validat() = 0; // פונקציה ווירטואלית לבדיקת תקינות
	void print() override;
	void printValidationError() override {};
	void reset() override {};

	void setUserInput(const T& input);
	T getUserInput();



protected:
	T m_userInput;

};




template<class T>
inline BaseField<T>::BaseField(const std::string& label)
	:AbstractField(label)
{}


template<class T>
inline void BaseField<T>::print()
{
	std::cout << m_userInput;
}

template<class T>
inline void BaseField<T>::setUserInput(const T& input)
{
	m_userInput = input;
}

template<class T>
inline T BaseField<T>::getUserInput()
{
	return m_userInput;
}



