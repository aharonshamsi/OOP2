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

class DialogueManager;


class BookingForm {

protected:
    std::vector <std::unique_ptr<AbstractField>> m_fields;

    void InitializingFields();

    //=========  מפה זה טיפול בכפתורים ובכותרות 
    Title m_titleLabel;
    sf::Font m_font;
    //========= 

    std::size_t activeField = 0; // מספר שדה פעיל
    sf::Clock cursorTimer;
    bool showCursor = true; // הצג סמן

    sf::RenderWindow& window; // חלון הזנת נתונים
    DialogueManager* formManager; // מצביע מטיפוס מנהל טופס

   // virtual void setDefaultValues()=0 ; // פונקציה ו
    void openConfirmationWindow();


    //================================================
    //============ פה זה טיפוסים לבדיקת תקינות טופס
    bool m_isFormValidat;
    virtual void ValidatBookingForm() = 0;
    virtual std::string formValidationError() = 0;
    virtual void resetForm() = 0;


public:
    BookingForm(sf::RenderWindow& win, DialogueManager* manager, const std::string& text, unsigned int fontSize);
    virtual ~BookingForm() = default;
    virtual std::string getFormType() const = 0;
    virtual void render(sf::RenderWindow& window) = 0;
    virtual void handleInput(sf::Event event) = 0;
};

#endif // BOOKINGFORM_H
