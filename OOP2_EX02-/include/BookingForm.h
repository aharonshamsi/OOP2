#ifndef BOOKINGFORM_H
#define BOOKINGFORM_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include <array>

#include "AbstractField.h"
#include "Name.h"
#include "Id.h"
#include "Email.h"
#include "Address.h"
#include "Title.h"
#include "FormButton.h"

class DialogueManager;

class BookingForm {

public:
    BookingForm(sf::RenderWindow& win, DialogueManager* manager, const std::string& text, unsigned int fontSize);

    virtual ~BookingForm() = default;
    virtual std::string getFormType() const = 0;
    virtual void render(sf::RenderWindow& window) = 0;
    virtual void handleInput(sf::Event event) = 0;


protected:
    std::vector <std::unique_ptr<AbstractField>> m_fields;
    std::vector<std::pair<std::string, bool>> m_selectionOptions;


    //Buttons
    Title m_titleLabel;                 // ✅ title Button
    sf::Font m_font;                    // ✅ All font
    FormButton m_doneButton;            // ✅ Done Button
    FormButton m_cancelButton;          // ✅ Cancel Button
    FormButton m_approveButton;         // ✅ Approve Button
    FormButton m_cancelButtonOutput;    // ✅ Cancel Output Button

    std::size_t activeField = 0; 
    sf::Clock cursorTimer;
    sf::RenderWindow& window; 
    DialogueManager* formManager; 

    bool showCursor = true;
    bool m_isFormValidat;

    void openConfirmationWindow();
    void drawButtons(sf::RenderWindow& window);
    void InitializingFields();
    virtual void ValidatBookingForm() = 0;
    virtual std::string formValidationError() = 0;
    virtual void resetForm() = 0;
    virtual void setDefaultOptions() = 0; 
    
private:
    void handleButtonClick(sf::RenderWindow& confirmWindow, bool& approved);
    void messageFormError(sf::RenderWindow& confirmWindow, const float& y);

};

#endif // BOOKINGFORM_H
