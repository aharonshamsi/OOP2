#ifndef FLIGHTBOOKINGFORM_H
#define FLIGHTBOOKINGFORM_H

#include "BookingForm.h"
#include <SFML/Graphics.hpp>
#include "DepartureAirport.h"
#include "ArrivalAirport.h"
#include "DepartureDate.h"
#include "PreferredTime.h"


class FlightBookingForm : public BookingForm {

public:
    FlightBookingForm(sf::RenderWindow& win, DialogueManager* manager); 

    void render(sf::RenderWindow& window) override;
    void handleInput(sf::Event event) override;
    std::string getFormType() const override;


private:

    void ValidatBookingForm() override;
    std::string formValidationError() override;
    void resetForm() override;
    void setDefaultOptions() override;
};

#endif 
