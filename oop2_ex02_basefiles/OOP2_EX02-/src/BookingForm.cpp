#include "BookingForm.h"
#include "DialogueManager.h"
#include <iostream>
#include <ctime>  // For getting current date

BookingForm::BookingForm(sf::RenderWindow& win, DialogueManager* manager, const std::string& text, unsigned int fontSize)
    :window(win), 
    formManager(manager), 
    m_isFormValidat(true),
    m_titleLabel(text, m_font, fontSize)
{
    m_font.loadFromFile("C:/Windows/Fonts/arialbd.ttf"); // אתחול הפונט
    m_titleLabel.setPosition(10.f, 10.f); // איתחול מיקום כותרת הטופס

    m_fields.push_back(std::make_unique<Name>("Name:"));
    m_fields.push_back(std::make_unique<Id>("Id:"));
    m_fields.push_back(std::make_unique<Address>("Address:"));
    m_fields.push_back(std::make_unique<Email>("Email:"));

    //userInput.resize(fieldLabels.size(), "");  // Initialize input fields

}

void BookingForm::InitializingFields()
{
    for (int i = 0; i < m_fields.size(); i++) {
        if (!m_fields[i]->getInputValid())
            m_fields[i]->reset();
    }
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
            if (event.type == sf::Event::Closed) {
                confirmWindow.close();
            }

            sf::Vector2f mousePos(event.mouseButton.x, event.mouseButton.y);

            if (event.type == sf::Event::MouseButtonPressed) {
                if (mousePos.x >= 280 && mousePos.x <= 400 && mousePos.y >= 550 && mousePos.y <= 595) {
                    confirmWindow.close();
                }
                if (mousePos.x >= 100 && mousePos.x <= 220 && mousePos.y >= 550 && mousePos.y <= 595) {
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


        //=============== זה השרשור של השדות והודעות השגיאה לתוך טקסט
        float y = 50;
        const float lineSpacing = 28.f;   // גובה שורת טקסט רגילה
        const float errorSpacing = 24.f;  // גובה שורת שגיאה – תמיד שמור מקום
        for (size_t i = 0; i < m_fields.size(); ++i) {
            // שורת קלט רגילה
            sf::Text line(m_fields[i]->print(), font, 18);
            line.setFillColor(sf::Color::Black);
            line.setPosition(50, y);
            confirmWindow.draw(line);
            y += lineSpacing;

            // שורת שגיאה (או ריקה, אבל נשמר מקום)
            std::string error = m_fields[i]->getMessageError();
            sf::Text errorText(error, font, 16);
            errorText.setFillColor(sf::Color(139, 0, 0)); // בורדו
            errorText.setPosition(60, y);  // טיפה פנימה
            if (!error.empty()) {
                confirmWindow.draw(errorText);
            }

            y += errorSpacing;
        }
        
        // ===== ת הודעת השגיאה ברמת הטופס
        std::string errorForm = formValidationError();
        sf::Text errorFormText(errorForm, m_font, 17);
        errorFormText.setFillColor(sf::Color(139, 0, 0));
        errorFormText.setPosition(60, y);
        if (!m_isFormValidat) {
            confirmWindow.draw(errorFormText);
        }




        // ✅ Approve Button
        sf::RectangleShape approveButton(sf::Vector2f(120, 40));
        approveButton.setPosition(100, 550);
        approveButton.setFillColor(sf::Color(50, 150, 50));
        confirmWindow.draw(approveButton);

        sf::Text approveText("APPROVE", font, 18);
        approveText.setFillColor(sf::Color::White);
        approveText.setPosition(118, 560);
        confirmWindow.draw(approveText);

        // ✅ Cancel Button
        sf::RectangleShape cancelButton(sf::Vector2f(120, 40));
        cancelButton.setPosition(280, 550);
        cancelButton.setFillColor(sf::Color(180, 0, 0));
        confirmWindow.draw(cancelButton);

        sf::Text cancelText("CANCEL", font, 18);
        cancelText.setFillColor(sf::Color::White);
        cancelText.setPosition(305, 560);
        confirmWindow.draw(cancelText);

        confirmWindow.display();


    }
    //=================
    InitializingFields(); //אם סגרת את החלון אתחול השדות שאם שגוי מאפסת אותם
    resetForm(); // איפוס ברמת הטופס

    if (approved) {
        formManager->closeForm();
    }
} 

