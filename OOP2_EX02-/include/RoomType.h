#pragma once
#include "SelectionOptions.h"

class RoomType : public SelectionOptions {

public:
	RoomType(const std::string& label) : SelectionOptions(label) {
		m_selectionOptions = { "Single Room", "Double Room", "Family Room", "Presidential Suite" };
		m_userInput = m_selectionOptions[3]; // Initializes to default

	}

	void reset() override {
		m_userInput = m_selectionOptions[3]; // Initializes to default
		m_isInputValid = true;
	}


};

