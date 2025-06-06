//// CarRentalForm.h - Handles Car Rental Bookings
//#ifndef CARRENTALFORM_H
//#define CARRENTALFORM_H
//
//#include "BookingForm.h"
//#include <array>
//
//// מחלקה טופס הרשמה של השכרת רכב
//class CarRentalForm : public BookingForm {
//    std::string pickupLocation, dropOffLocation, carType;
//public:
//    CarRentalForm(sf::RenderWindow& win, DialogueManager* manager);    
//    std::string getFormType() const override;
//    void render(sf::RenderWindow& window) override;
//    void handleInput(sf::Event event) override;
//private:
//    void setDefaultValues();
//    std::array<std::string, 5> carTypeSelection = { "Economy","Compact","Sedan","SUV","Luxury"};
//    int selectedCarType = 0;
//};
//
//#endif // CARRENTALFORM_H
