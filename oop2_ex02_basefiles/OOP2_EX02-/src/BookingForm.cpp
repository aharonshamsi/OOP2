#include "BookingForm.h"
#include "DialogueManager.h"
#include <iostream>
#include <ctime>  // For getting current date

BookingForm::BookingForm(sf::RenderWindow& win, DialogueManager* manager, const std::string& text, unsigned int fontSize)
    :window(win), 
    formManager(manager), 
    m_isFormValidat(true),
    m_titleLabel(text, m_font, fontSize),
    m_doneButton({ 140, 40 }, { 20, 550 }, sf::Color(50, 150, 50), "DONE", m_font, 20),
    m_cancelButton({ 140, 40 }, { 200, 550 }, sf::Color(180, 0, 0), "CANCEL", m_font, 20), 
    m_approveButton({ 135, 40 }, { 100, 550 }, sf::Color(50, 150, 50), "APPROVE", m_font, 18),
    m_cancelButtonOutput({ 120, 40 }, { 280, 550 }, sf::Color(180, 0, 0), "CANCEL", m_font, 18)
    
{
    m_font.loadFromFile("C:/Windows/Fonts/arialbd.ttf"); // Initialize the font
    m_titleLabel.setPosition(10.f, 10.f); // Initialize the form title position

    m_fields.push_back(std::make_unique<Name>("Name:"));
    m_fields.push_back(std::make_unique<Id>("Id:"));
    m_fields.push_back(std::make_unique<Address>("Address:"));
    m_fields.push_back(std::make_unique<Email>("Email:"));

}


void BookingForm::openConfirmationWindow() {
    const std::string& formTitle = getFormType();
    sf::RenderWindow confirmWindow(sf::VideoMode(500, 600), "Confirm " + formTitle);

    bool approved = false;

    while (confirmWindow.isOpen()) {

        handleButtonClick(confirmWindow, approved);

        confirmWindow.clear(sf::Color(240, 240, 240));
        sf::Text title("Confirm " + formTitle, m_font, 22);
        title.setFillColor(sf::Color::Black);
        title.setStyle(sf::Text::Bold);
        title.setPosition(130, 20);
        confirmWindow.draw(title); 


        float y = 50;
        const float lineSpacing = 25.f;
        const float errorSpacing = 21.f;
        for (size_t i = 0; i < m_fields.size(); ++i) {

            sf::Text line(m_fields[i]->print(), m_font, 18);
            line.setFillColor(sf::Color::Black);
            line.setPosition(50, y);
            confirmWindow.draw(line);
            y += lineSpacing;

            std::string error = m_fields[i]->getMessageError();
            sf::Text errorText(error, m_font, 16);
            errorText.setFillColor(sf::Color(139, 0, 0)); 
            errorText.setPosition(60, y); 

            if (!error.empty()) {
                confirmWindow.draw(errorText);
            }

            y += errorSpacing;
        }
        // The form-level error message
        messageFormError(confirmWindow, y);
    }

    InitializingFields(); // Initialize fields
    resetForm();

    if (approved) {
        formManager->closeForm();
    }
} 


//==================================================================================
void BookingForm::messageFormError(sf::RenderWindow& confirmWindow, const float& y)
{
    std::string errorForm = formValidationError();
    sf::Text errorFormText(errorForm, m_font, 17);
    errorFormText.setFillColor(sf::Color(139, 0, 0));
    errorFormText.setPosition(60, y);

    if (!m_isFormValidat) {
        confirmWindow.draw(errorFormText);
    }

    m_approveButton.draw(confirmWindow);
    m_cancelButtonOutput.draw(confirmWindow);
    confirmWindow.display();
}


//==================================================================================
void BookingForm::handleButtonClick(sf::RenderWindow& confirmWindow, bool& approved)
{
    sf::Event event;
    while (confirmWindow.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            confirmWindow.close();
        }

        sf::Vector2f mousePos(event.mouseButton.x, event.mouseButton.y);

        if (event.type == sf::Event::MouseButtonPressed) {
            if (mousePos.x >= 280 && mousePos.x <= 400 && mousePos.y >= 550 && mousePos.y <= 595) {
                confirmWindow.close();
            }
            if (mousePos.x >= 100 && mousePos.x <= 220 && mousePos.y >= 550 && mousePos.y <= 595) {
                std::cout << getFormType() << " Confirmed! Returning to main menu." << std::endl;
                approved = true;
                confirmWindow.close();
            }
        }
    }
}


//==================================================================================
void BookingForm::InitializingFields()
{
    if (!m_fields[m_fields.size() - 1]->getInputValid()) {
        for (auto& option : m_selectionOptions) {
            option.second = false;
        }
        m_selectionOptions[m_selectionOptions.size() - 1].second = true;
    }

    for (int i = 0; i < m_fields.size(); i++) {
        if (!m_fields[i]->getInputValid())
            m_fields[i]->reset();
    }
}

void BookingForm::drawButtons(sf::RenderWindow& window)
{
    m_doneButton.draw(window);
    m_cancelButton.draw(window);
}
