//#ifndef TRAINBOOKINGFORM_H
//#define TRAINBOOKINGFORM_H
//
//#include "BookingForm.h"
//
//// מחלקה של רכבת
//class TrainBookingForm : public BookingForm {
//public:
//    TrainBookingForm(sf::RenderWindow& win, DialogueManager* manager);
//    std::string getFormType() const override;
//    void render(sf::RenderWindow& window) override;
//    void handleInput(sf::Event event) override;
//private:
//    void setDefaultValues() override; 
//    std::array<std::pair<std::string, bool>, 5> timeSelection = {
//            std::make_pair("Morning", false),
//            std::make_pair("Noon", false),
//            std::make_pair("Evening", false),
//            std::make_pair("Night", false),
//            std::make_pair("Don't Care", true)  // ✅ Default selection
//    };
//    std::array<std::pair<std::string, bool>, 4> specialSelection = {
//        std::make_pair("Quiet Zone", false),
//        std::make_pair("Family Section", false),
//        std::make_pair("First Class", false) ,
//        std::make_pair("None", true)
//    };
//};
//
//#endif // TRAINBOOKINGFORM_H
