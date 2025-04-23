#pragma once
#include <iostream>
#include "flightType.h"

template <class T>
class BaseField {

public:
	BaseField(const std::string& fiels, flightType type);

	virtual void validator() = 0; // פונקציה ווירטואלית לבדיקת תקינות
	virtual void print() = 0;

protected:
	std::string m_label;
	T m_userInput;
	flightType m_type; // זה חופף לממבר שמייצג איזה שדה פעיל activeField 
	bool m_isInputValid;
};

template<class T>
inline BaseField<T>::BaseField(const std::string& label, flightType type)
	:m_label(label), m_type(type), m_isInputValid(false)
{}


