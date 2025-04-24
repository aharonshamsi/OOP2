#pragma once
#include <iostream>
#include "AbstractField.h"

template <class T>
class BaseField : public AbstractField {

public:

	BaseField(const std::string& fiels);

	virtual void validator() = 0; // פונקציה ווירטואלית לבדיקת תקינות

	void input() override;
	void print() override;

protected:
	T m_userInput;
	bool m_isInputValid;


};

template<class T>
inline BaseField<T>::BaseField(const std::string& label)
	:AbstractField(label),
	m_isInputValid(false)
{}


template<class T>
inline void BaseField<T>::input()
{
	std::cin >> m_userInput;
}

template<class T>
inline void BaseField<T>::print()
{
	std::cout << m_userInput;
}


