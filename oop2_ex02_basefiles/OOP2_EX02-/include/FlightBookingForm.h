#ifndef FLIGHTBOOKINGFORM_H
#define FLIGHTBOOKINGFORM_H

#include "BookingForm.h"
#include <SFML/Graphics.hpp>

class FlightBookingForm : public BookingForm {
private:    
    void setDefaultValues() override;
    
    std::array<std::pair<std::string, bool>, 5> timeSelection = {
        std::make_pair("Morning", false),
        std::make_pair("Noon", false),
        std::make_pair("Evening", false),
        std::make_pair("Night", false),
        std::make_pair("Don't Care", true)  // ✅ Default selection
    };

public:
    FlightBookingForm(sf::RenderWindow& win, DialogueManager* manager);  // ✅ Updated constructor
    std::string getFormType() const override;
    void render(sf::RenderWindow& window) override;
    void handleInput(sf::Event event) override;
};

#endif // FLIGHTBOOKINGFORM_H
