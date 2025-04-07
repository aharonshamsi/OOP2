#include "BookingForm.h"
#include "DialogueManager.h"
#include <iostream>
#include <ctime>  // For getting current date

BookingForm::BookingForm(sf::RenderWindow& win, DialogueManager* manager) :window(win), formManager(manager) {
    fieldLabels = { "Name:", "ID:", "Address:", "Email:" };  // ✅ Add common fields
    userInput.resize(fieldLabels.size(), "");  // Initialize input fields
}

void BookingForm::openConfirmationWindow() {
    const std::string& formTitle = getFormType();
    sf::RenderWindow confirmWindow(sf::VideoMode(500, 600), "Confirm " + formTitle);

    sf::Font font;
    font.loadFromFile("C:/Windows/Fonts/arialbd.ttf");

    bool approved = false;

    while (confirmWindow.isOpen()) {
        sf::Event event;
        while (confirmWindow.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                confirmWindow.close();

            sf::Vector2f mousePos(event.mouseButton.x, event.mouseButton.y);

            if (event.type == sf::Event::MouseButtonPressed) {
                if (mousePos.x >= 280 && mousePos.x <= 400 && mousePos.y >= 300 && mousePos.y <= 345) {
                    confirmWindow.close();
                }
                if (mousePos.x >= 100 && mousePos.x <= 220 && mousePos.y >= 300 && mousePos.y <= 345) {
                    std::cout << formTitle << " Confirmed! Returning to main menu." << std::endl;
                    approved = true;
                    confirmWindow.close();
                }
            }
        }

        confirmWindow.clear(sf::Color(240, 240, 240));

        sf::Text title("Confirm " + formTitle, font, 22);
        title.setFillColor(sf::Color::Black);
        title.setStyle(sf::Text::Bold);
        title.setPosition(130, 20);
        confirmWindow.draw(title);

        std::string bookingInfo;
        for (size_t i = 0; i < fieldLabels.size(); ++i) {
            bookingInfo += fieldLabels[i] + " " + userInput[i] + "\n";
        }

        sf::Text details(bookingInfo, font, 18);
        details.setFillColor(sf::Color::Black);
        details.setPosition(50, 80);
        confirmWindow.draw(details);

        // ✅ Approve Button
        sf::RectangleShape approveButton(sf::Vector2f(120, 40));
        approveButton.setPosition(100, 300);
        approveButton.setFillColor(sf::Color(50, 150, 50));
        confirmWindow.draw(approveButton);

        sf::Text approveText("APPROVE", font, 18);
        approveText.setFillColor(sf::Color::White);
        approveText.setPosition(118, 310);
        confirmWindow.draw(approveText);

        // ✅ Cancel Button
        sf::RectangleShape cancelButton(sf::Vector2f(120, 40));
        cancelButton.setPosition(280, 300);
        cancelButton.setFillColor(sf::Color(180, 0, 0));
        confirmWindow.draw(cancelButton);

        sf::Text cancelText("CANCEL", font, 18);
        cancelText.setFillColor(sf::Color::White);
        cancelText.setPosition(305, 310);
        confirmWindow.draw(cancelText);

        confirmWindow.display();
    }

    if (approved) {
        formManager->closeForm();
    }
}
