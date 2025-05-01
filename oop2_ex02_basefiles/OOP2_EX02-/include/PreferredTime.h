#pragma once
#include "SelectionOptions.h"

class PreferredTime : public SelectionOptions {

public:
	PreferredTime(const std::string& label) :SelectionOptions(label) 
	{
		m_selectionOptions = { "Morning", "Noon", "Evening", "Night", "Don't Care" };
		m_userInput = m_selectionOptions[4]; // מאתחל אותו דיפולט לdont care
	}


};
