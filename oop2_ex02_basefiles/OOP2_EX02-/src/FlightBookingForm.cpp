#include "FlightBookingForm.h"
#include "DialogueManager.h"
#include <iostream>


//==================================================================================================
FlightBookingForm::FlightBookingForm(sf::RenderWindow& win, DialogueManager* manager)
    : BookingForm(win, manager, "Flight Booking Form", 26) {  // ✅ Calls base constructor

    m_fields.push_back(std::make_unique<DepartureAirport>("Departure Airport:"));
    m_fields.push_back(std::make_unique<ArrivalAirport>("Arrival Airport:"));
    m_fields.push_back(std::make_unique<DepartureDate>("Departure Date:"));
    m_fields.push_back(std::make_unique<PreferredTime>("Preferred Time:"));

    //setDefaultValues();
}
    
//
//void FlightBookingForm::setDefaultValues() {
//    time_t now = time(0);
//    tm ltm;
//    localtime_s(&ltm, &now);  // ✅ Safe alternative to localtime()
//}

std::string FlightBookingForm::getFormType() const {
    return "Flight Booking";
}

//==================================================================================================
void FlightBookingForm::render(sf::RenderWindow& window) {
      
    window.clear(sf::Color(235, 235, 235));
    m_titleLabel.draw(window); // זה הכותרת בראש הטופס

    bool cursorVisible = (cursorTimer.getElapsedTime().asMilliseconds() % 1000 < 500); // הבהוב סמן 

    // ✅ Loop through form fields and render
    //======זאת הלולאה שמציגה את השדות תוית וקלט אל טקסט ואל החלון =========================
    int yOffset = 60;
    for (std::size_t i = 0; i < m_fields.size(); ++i) {
        sf::Text label(m_fields[i]->getLabel(), m_font, 18);
        label.setFillColor(sf::Color(60, 60, 60));
        label.setPosition(20, yOffset);
        window.draw(label);

        sf::RectangleShape inputBox(sf::Vector2f(350, 35));
        inputBox.setPosition(240, yOffset - 5);
        inputBox.setFillColor(sf::Color::White);
        inputBox.setOutlineThickness(2);
        inputBox.setOutlineColor(i == activeField ? sf::Color(0, 120, 255) : sf::Color(160, 160, 160));
        window.draw(inputBox);

        std::string displayText = m_fields[i]->getUserInputAsString();
        if (i == activeField && cursorVisible) {
            displayText += "|";
        }

        sf::Text inputText(displayText, m_font, 16);
        inputText.setFillColor(sf::Color::Black);
        inputText.setPosition(245, yOffset);
        window.draw(inputText);  

        yOffset += 50;
    }
    //=========================================================================

    // ✅ Time Selection Button
    float timeButtonX = 10;
    for (std::size_t i = 0; i < timeSelection.size(); ++i) {
        sf::RectangleShape timeButton(sf::Vector2f(100, 30));
        timeButton.setPosition(timeButtonX, yOffset);
        timeButton.setFillColor(timeSelection[i].second ? sf::Color(0, 120, 255) : sf::Color::White);
        timeButton.setOutlineThickness(2);
        timeButton.setOutlineColor(sf::Color(160, 160, 160));
        window.draw(timeButton);

        sf::Text timeText(timeSelection[i].first, m_font, 16);
        timeText.setFillColor(timeSelection[i].second ? sf::Color::White : sf::Color::Black);
        timeText.setPosition(timeButtonX + 10, yOffset+2);
        window.draw(timeText);

        timeButtonX += 110;  // ✅ Increased spacing between buttons
    }

    //==================================================================================================
    // את שתי הכפתורים האלו נייצא למחלקה ותהא הכלה באבא
    // ✅ "Done" Button
    sf::RectangleShape submitButton(sf::Vector2f(140, 40));
    submitButton.setPosition(20, 550);
    submitButton.setFillColor(sf::Color(50, 150, 50));  // ✅ Green color
    window.draw(submitButton);

    sf::Text submitText("DONE", m_font, 20);
    submitText.setFillColor(sf::Color::White);
    submitText.setPosition(50, 560);
    window.draw(submitText);

    // ✅ "Cancel" Button
    sf::RectangleShape cancelButton(sf::Vector2f(140, 40));
    cancelButton.setPosition(200, 550);
    cancelButton.setFillColor(sf::Color(180, 0, 0));  // ✅ Red color
    window.draw(cancelButton);

    sf::Text cancelText("CANCEL", m_font, 20);
    cancelText.setFillColor(sf::Color::White);
    cancelText.setPosition(230, 560);
    window.draw(cancelText);
    //==================================================================================================


}

//==================================================================================================
//==================================================================================================
void FlightBookingForm::handleInput(sf::Event event) {
    if (event.type == sf::Event::TextEntered) {
        if (event.text.unicode == '\b' && !m_fields[activeField]->isEmpty()) { 
            //m_fields[activeField].pop_back();  // ✅ Handle Backspace    // ============ פה לטפל ולבדוק מה זה השורה הזאת כי ביטלתי אותה
        } 
        else if (event.text.unicode >= 32 && event.text.unicode < 128) {
            m_fields[activeField]->addChar(static_cast<char>(event.text.unicode)); // פה נשלח תו בהתאם לשדה שבו אנו נמצאים
        }
    } 

    else if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::Tab) {
            activeField = (activeField + 1) % m_fields.size();  // ✅ Move to next input field
        }
        if (event.key.code == sf::Keyboard::Return) {
            std::cout << "Entered Data: ";
            for (const auto& field : m_fields) std::cout << field << " ";
            std::cout << std::endl;
        }
    }
    else if (event.type == sf::Event::MouseButtonPressed) {
        sf::Vector2f mousePos(event.mouseButton.x, event.mouseButton.y);

        int yOffset = 60;  // ✅ Start from the top

        for (std::size_t i = 0; i < m_fields.size(); ++i) {
            sf::FloatRect inputBoxBounds(260, yOffset - 5, 250, 35);  // ✅ Uses dynamic positioning
            if (inputBoxBounds.contains(mousePos)) {
                activeField = i;
                return;
            }
            yOffset += 50;  // ✅ Move down dynamically (same logic as `render()`)
        }


        // ✅ Handle Time Selection Button Click          
        float timeButtonX = 10;
               
        for (int i = 0; i < 5; ++i) {           
            sf::FloatRect timeButtonBounds(timeButtonX, yOffset, 100, 30);
            if (timeButtonBounds.contains(mousePos)) {                
                timeSelection[i].second = !timeSelection[i].second;
                return;
            }
            timeButtonX += 110;  // Move to next button
            
        }
    

        // ✅ Handle "Done" Button Click
        if (mousePos.x >= 20 && mousePos.x <= 160 && mousePos.y >= 550 && mousePos.y <= 590) {
            std::cout << "Flight Booking Confirmed!\n";

            //========= פה נבצע בידקות תקינות של קלט  ===========
            for (int i = 0; i < m_fields.size(); i++) {
                m_fields[i]->validat();
                std::cout << m_fields[i]->getMessageError();
            }

            // פונקציה של בדיקת טופס
            ValidatBookingForm();
            formValidationError();

            openConfirmationWindow();  // ✅ Open confirmation


            return;
        }

        // ✅ Handle "Cancel" Button Click
        if (mousePos.x >= 200 && mousePos.x <= 340 && mousePos.y >= 550 && mousePos.y <= 590) {
            std::cout << "Cancelled Flight Booking\n";
            formManager->closeForm();
            return;
        }
    }

}


//=========פונקצית שהוספתי לבדיקת תקינות טופס ====================================================
void FlightBookingForm::ValidatBookingForm()
{
    if (m_fields[4]->getUserInputAsString() == m_fields[5]->getUserInputAsString())
        m_isFormValidat = false;
}

std::string FlightBookingForm::formValidationError()
{
    if (!m_isFormValidat) {
        return std::string("**********************\n") +
            "Form validators:\n" +
            "    Departure and Arrival airports must be different.\n";
    }
    return "";
}

void FlightBookingForm::resetForm()
{
    if (!m_isFormValidat) {
        m_isFormValidat = true;
        m_fields[4]->setUserInput("");
        m_fields[5]->setUserInput("");
    }
}

