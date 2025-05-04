#include "HotelBookingForm.h"
#include "DialogueManager.h"
#include <iostream>
#include <ctime>  // For getting current date

HotelBookingForm::HotelBookingForm(sf::RenderWindow& win, DialogueManager* manager)
    : BookingForm(win, manager, "Hotel Booking Form", 26) { 

    m_fields.push_back(std::make_unique<HotelName>("Hotel Name:"));
    m_fields.push_back(std::make_unique<CheckInDate>("Check-in Date:"));
    m_fields.push_back(std::make_unique<CheckOutDate>("Check-out Date:"));
    m_fields.push_back(std::make_unique<NumberGuests>("Number of Guests:"));
    m_fields.push_back(std::make_unique<RoomType>("Room Type:"));

    setDefaultOptions();
}

std::string HotelBookingForm::getFormType() const {
    return "Hotel Booking";
}

void HotelBookingForm::render(sf::RenderWindow& window) {

    // Form title
    window.clear(sf::Color(235, 235, 235));
    m_titleLabel.draw(window); 

    bool cursorVisible = (cursorTimer.getElapsedTime().asMilliseconds() % 1000 < 500);

    // ✅ Render input fields dynamically
    int yOffset = 60;
    for (std::size_t i = 0; i < m_fields.size(); ++i) {

        sf::Text label(m_fields[i]->getLabel(), m_font, 18);
        label.setFillColor(sf::Color(60, 60, 60));
        label.setPosition(20, yOffset);
        window.draw(label);

        sf::RectangleShape inputBox(sf::Vector2f(250, 35));
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

    float roomTypeButtonX = 10;
    for (int i = 0; i < m_selectionOptions.size(); ++i) {
        sf::RectangleShape roomButton(sf::Vector2f(150, 30));
        roomButton.setPosition(roomTypeButtonX, yOffset);
        // פה שונה ושגיאה לשנות
        roomButton.setFillColor(m_selectionOptions[i].second ? sf::Color(0, 120, 255) : sf::Color::White);  // ✅ Highlight selected
        roomButton.setOutlineThickness(2);
        roomButton.setOutlineColor(sf::Color(160, 160, 160));
        window.draw(roomButton);

        sf::Text roomText(m_selectionOptions[i].first, m_font, 16);
        roomText.setFillColor(m_selectionOptions[i].second ? sf::Color::White : sf::Color::Black);
        roomText.setPosition(roomTypeButtonX + 10, yOffset + 5);
        window.draw(roomText);

        roomTypeButtonX += 160;  // ✅ Increased spacing
    }

    // Print buttons Donc & Cancel
    drawButtons(window);
}


//====================================================================================
void HotelBookingForm::handleInput(sf::Event event) {
    if (event.type == sf::Event::TextEntered) {
        if (event.text.unicode == '\b' && !m_fields[activeField]->isEmpty()) {
            m_fields[activeField]->deleteLastChar();
        }
        else if (event.text.unicode >= 32 && event.text.unicode < 128) {
            m_fields[activeField]->addChar(static_cast<char>(event.text.unicode)); 

        }
    }
    else if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::Tab) {
            activeField = (activeField + 1) % m_fields.size();
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

        // ✅ Handle Room Type Button Click          
        float roomButtonX = 10;
        for (int i = 0; i < 4; ++i) {
            sf::FloatRect timeButtonBounds(roomButtonX, yOffset, 150, 30);
            if (timeButtonBounds.contains(mousePos) && activeField == 8) {
                for (auto& option : m_selectionOptions) {
                    option.second = false;
                }
                m_selectionOptions[i].second = true;
                m_fields[8]->setUserInput(m_selectionOptions[i].first);  // Update field input
                return;
            }

            roomButtonX += 160;
        }

        // ✅ Handle "Done" Button Click
        if (mousePos.x >= 20 && mousePos.x <= 160 && mousePos.y >= 550 && mousePos.y <= 590) {
            std::cout << "Flight Booking Confirmed!\n";

            // Checking the validity of the fields
            for (int i = 0; i < m_fields.size(); i++) {
                m_fields[i]->validat();
            }

            // File integrity and error printing
            ValidatBookingForm();
            formValidationError();
            openConfirmationWindow();  

            return;
        }

        // ✅ Handle "Cancel" Button Click
        if (mousePos.x >= 200 && mousePos.x <= 340 && mousePos.y >= 570 && mousePos.y <= 610) {
            std::cout << "Cancelled Flight Booking\n";
            formManager->closeForm();
            return;
        }
    }
}


//====================================================================================
void HotelBookingForm::ValidatBookingForm()
{

    if (!isRoomGuestMatch()) {
        m_isFormValidat = false;
    }

    // Departure date before arrival date
    if (!isExitAfterEntry()) {
        m_isFormValidat = false;
    }

}

std::string HotelBookingForm::formValidationError()
{
    if (!m_isFormValidat) {
        return std::string("**********************\n") +
            "Form validators:\n" +
            "    Departure and Arrival hotel must be different.\n";
    }
    return "";
}

void HotelBookingForm::resetForm()
{
    if (!m_isFormValidat) {
        m_isFormValidat = true;
    }
}

void HotelBookingForm::setDefaultOptions()
{
    m_selectionOptions = {
   {"Single Room", false},
   {"Double Room", false},
   {"Family Room", false},
   {"Presidential Suite", true}
    };
}


bool HotelBookingForm::isRoomGuestMatch()
{
    int numGuests = std::stoi(m_fields[7]->getUserInputAsString());

    if ((m_fields[8]->getUserInputAsString() == m_selectionOptions[0].first) &&
        (m_fields[7]->getUserInputAsString() != "1") ||
        (m_fields[8]->getUserInputAsString() == m_selectionOptions[1].first) &&
        (m_fields[7]->getUserInputAsString() != "2") ||
        (m_fields[8]->getUserInputAsString() == m_selectionOptions[3].first) && (numGuests > 6)) {
        return false;
    }
    return true;
}


bool HotelBookingForm::isExitAfterEntry()
{
    std::string checkInStr = m_fields[5]->getUserInputAsString();
    std::string checkOutStr = m_fields[6]->getUserInputAsString();

    if (!checkInStr.empty() && !checkOutStr.empty()) {
        Date checkIn, checkOut;
        checkIn.setUserInput(checkInStr);
        checkOut.setUserInput(checkOutStr);

        checkIn.validat();
        checkOut.validat();

        if (checkOut < checkIn) {
            return false;

        }
        else
            return true;
    }
    return true;
}
