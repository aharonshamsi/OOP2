#pragma once
#include "Date.h"

class DepartureDate : public Date {

public:
	DepartureDate(const std::string& label) : Date(label) {};
};
