#include "TrainBookingForm.h"
#include "DialogueManager.h"
#include <iostream>
#include <ctime>  // For getting current date

TrainBookingForm::TrainBookingForm(sf::RenderWindow& win, DialogueManager* manager)
    : BookingForm(win, manager) {  // ✅ Calls base constructor
    fieldLabels.insert(fieldLabels.end(), {
        "Departure Station:", "Arrival Station:", "Departure Date:",
        "Number of Passengers:","Preferred Time:", "Special Requests:", 
        });

    userInput.resize(fieldLabels.size(), "");  // ✅ Resize input fields
    setDefaultValues();
}

void TrainBookingForm::setDefaultValues() {
    time_t now = time(0);
    tm ltm;
    localtime_s(&ltm, &now);  // ✅ Safe alternative to localtime()

    userInput[6] = std::to_string(1900 + ltm.tm_year) + "-" +
        std::to_string(1 + ltm.tm_mon) + "-" +
        std::to_string(ltm.tm_mday);
	userInput[8] = "Don't Care";
    userInput[9] = "None";
}

std::string TrainBookingForm::getFormType() const {
    return "Train Booking";
}

void TrainBookingForm::render(sf::RenderWindow& window) {
    sf::Font font;
    font.loadFromFile("C:/Windows/Fonts/arialbd.ttf");

    window.clear(sf::Color(235, 235, 235));

    // ✅ Title
    sf::Text title("Train Booking Form", font, 26);
    title.setFillColor(sf::Color(20, 20, 20));
    title.setStyle(sf::Text::Bold);
    title.setPosition(20, 10);
    window.draw(title);

    bool cursorVisible = (cursorTimer.getElapsedTime().asMilliseconds() % 1000 < 500);

    // ✅ Render input fields dynamically
    int yOffset = 60;
    for (std::size_t i = 0; i < fieldLabels.size(); ++i) {
        sf::Text label(fieldLabels[i], font, 18);
        label.setFillColor(sf::Color(60, 60, 60));
        label.setPosition(20, yOffset);
        window.draw(label);

        sf::RectangleShape inputBox(sf::Vector2f(350, 35));
        inputBox.setPosition(240, yOffset - 5);
        inputBox.setFillColor(sf::Color::White);
        inputBox.setOutlineThickness(2);
        inputBox.setOutlineColor(i == activeField ? sf::Color(0, 120, 255) : sf::Color(160, 160, 160));
        window.draw(inputBox);

        std::string displayText = userInput[i];
        if (i == activeField && cursorVisible) {
            displayText += "|";
        }

        sf::Text inputText(displayText, font, 16);
        inputText.setFillColor(sf::Color::Black);
        inputText.setPosition(245, yOffset);
        window.draw(inputText);

        if (i == 8)
        {
            yOffset += 40;
            // ✅ Time Selection Buttons
            float timeButtonX = 10;
            for (std::size_t i = 0; i < timeSelection.size(); ++i) {
                sf::RectangleShape timeButton(sf::Vector2f(100, 30));
                timeButton.setPosition(timeButtonX, yOffset);
                timeButton.setFillColor(timeSelection[i].second ? sf::Color(0, 120, 255) : sf::Color::White);
                timeButton.setOutlineThickness(2);
                timeButton.setOutlineColor(sf::Color(160, 160, 160));
                window.draw(timeButton);

                sf::Text timeText(timeSelection[i].first, font, 16);
                timeText.setFillColor(timeSelection[i].second ? sf::Color::White : sf::Color::Black);
                timeText.setPosition(timeButtonX + 10, yOffset + 2);
                window.draw(timeText);

                timeButtonX += 110;  // ✅ Increased spacing between buttons
            }
        } 
        if (i == 9)
        {
            yOffset += 40;
			// ✅ Special Selection Buttons
            float specialX = 10;
            for (std::size_t i = 0; i < specialSelection.size(); ++i) {
                sf::RectangleShape sButton(sf::Vector2f(150, 30));
                sButton.setPosition(specialX, yOffset);
                sButton.setFillColor(specialSelection[i].second ? sf::Color(0, 120, 255) : sf::Color::White);
                sButton.setOutlineThickness(2);
                sButton.setOutlineColor(sf::Color(160, 160, 160));
                window.draw(sButton);

                sf::Text timeText(specialSelection[i].first, font, 16);
                timeText.setFillColor(specialSelection[i].second ? sf::Color::White : sf::Color::Black);
                timeText.setPosition(specialX + 10, yOffset + 2);
                window.draw(timeText);

                specialX+= 160;  // ✅ Increased spacing between buttons
            }
        }
       
      yOffset += 50;
    }
   
    // ✅ "Done" and "Cancel" Buttons (positioned dynamically)
    yOffset +=10;

    sf::RectangleShape submitButton(sf::Vector2f(140, 40));
    submitButton.setPosition(20, yOffset);
    submitButton.setFillColor(sf::Color(50, 150, 50));
    window.draw(submitButton);

    sf::Text submitText("DONE", font, 20);
    submitText.setFillColor(sf::Color::White);
    submitText.setPosition(50, yOffset + 10);
    window.draw(submitText);

    sf::RectangleShape cancelButton(sf::Vector2f(140, 40));
    cancelButton.setPosition(200, yOffset);
    cancelButton.setFillColor(sf::Color(180, 0, 0));
    window.draw(cancelButton);

    sf::Text cancelText("CANCEL", font, 20);
    cancelText.setFillColor(sf::Color::White);
    cancelText.setPosition(230, yOffset + 10);
    window.draw(cancelText);
}

void TrainBookingForm::handleInput(sf::Event event) {
    if (event.type == sf::Event::TextEntered) {
        if (event.text.unicode == '\b' && !userInput[activeField].empty()) {
            userInput[activeField].pop_back();
        }
        else if (event.text.unicode >= 32 && event.text.unicode < 128) {
            userInput[activeField] += static_cast<char>(event.text.unicode);
        }
    }
    else if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::Tab) {
            activeField = (activeField + 1) % userInput.size();
        }
        if (event.key.code == sf::Keyboard::Return) {
            std::cout << "Entered Data: ";
            for (const auto& field : userInput) std::cout << field << " ";
            std::cout << std::endl;
        }
    }
    else if (event.type == sf::Event::MouseButtonPressed) {
        sf::Vector2f mousePos(event.mouseButton.x, event.mouseButton.y);
        int yOffset = 60, timeOffset = 0, specialOffset = 0;
        for (std::size_t i = 0; i < fieldLabels.size(); ++i) {
            sf::FloatRect inputBoxBounds(240, yOffset - 5, 250, 35);
            if (inputBoxBounds.contains(mousePos)) {
                activeField = i;
                return;
            }
            if (i ==8)            
                timeOffset= yOffset +=40;
            if (i==9)
                specialOffset = yOffset +=40;
            yOffset += 50;
        }
        // ✅ Handle Time Selection Button Click          
        float timeButtonX = 10;

		for (int i = 0; i < timeSelection.size(); ++i) {
            sf::FloatRect timeButtonBounds(timeButtonX, timeOffset, 100, 30);
            if (timeButtonBounds.contains(mousePos)) {
                timeSelection[i].second = !timeSelection[i].second;
                //Update the "Preferred Time" input box
                userInput[8] = "";
                for (int i = 0; i < timeSelection.size(); ++i) {
                    if (timeSelection[i].second) {
                        if (!userInput[8].empty()) userInput[8] += "| ";  // ✅ Separate multiple selections
                        userInput[8] += timeSelection[i].first;
                    }
                }

                return;
            }
            timeButtonX += 110;  // Move to next button
        }
        // ✅ Handle Special Selection Botton click
        float sButtonX = 10;

		for (int i = 0; i < specialSelection.size(); ++i) {
            sf::FloatRect specialSelectionBounds(sButtonX, specialOffset, 150, 30);
            if (specialSelectionBounds.contains(mousePos)) {
                specialSelection[i].second = !specialSelection[i].second;
                //Update the "Preferred Time" input box
                userInput[9] = "";
                for (int i = 0; i < specialSelection.size(); ++i) {
                    if (specialSelection[i].second) {
                        if (!userInput[9].empty()) userInput[9] += "| ";  // ✅ Separate multiple selections
                        userInput[9] += specialSelection[i].first;
                    }
                }

                return;
            }
            sButtonX += 160;  // Move to next button
            
        }
        yOffset += 10;

        if (mousePos.x >= 20 && mousePos.x <= 160 && mousePos.y >= yOffset && mousePos.y <= yOffset + 40) {
            std::cout << "Train Booking Confirmed!\n";
            openConfirmationWindow();
            return;
        }

        if (mousePos.x >= 200 && mousePos.x <= 340 && mousePos.y >= yOffset && mousePos.y <= yOffset + 40) {
            std::cout << "Cancelled Train Booking\n";
            formManager->closeForm();
            return;
        }
    }
}
