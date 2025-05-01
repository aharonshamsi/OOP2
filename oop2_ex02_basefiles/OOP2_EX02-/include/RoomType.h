#pragma once
#include "SelectionOptions.h"

class RoomType : public SelectionOptions {

public:
	RoomType(const std::string& label) : SelectionOptions(label) {
		m_selectionOptions = { "Single Room", "Double Room", "Family Room", "Presidential Suite" };
	}

	std::string getMessageError() override {
		if(!m_isInputValid)
			return "Error: Invalid room type selected. Please choose one of the available room types from the list.\n";
		return;
	}

};

