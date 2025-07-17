#ifndef HOTELBOOKINGFORM_H
#define HOTELBOOKINGFORM_H

#include "BookingForm.h"
#include "HotelName.h"
#include "CheckInDate.h"
#include "CheckOutDate.h"
#include "NumberGuests.h"
#include "RoomType.h"
#include "Date.h"

class HotelBookingForm : public BookingForm {

public:
    HotelBookingForm(sf::RenderWindow& win, DialogueManager* manager);

    void render(sf::RenderWindow& window) override;
    void handleInput(sf::Event event) override;
    std::string formValidationError() override;
    std::string getFormType() const override;
    void ValidatBookingForm() override;
    void resetForm() override;
    void setDefaultOptions() override;

private:
    bool isRoomGuestMatch();
    bool isExitAfterEntry();

};

#endif // HOTELBOOKINGFORM_H

