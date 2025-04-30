#ifndef BOOKINGFORM_H
#define BOOKINGFORM_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include <array>

//=============================
#include "AbstractField.h"
#include "Name.h"
#include "Id.h"
#include "Email.h"
#include "Address.h"


class DialogueManager;

struct PersonalInfo {
    std::string name;
    std::string id;
    std::string address;
    std::string email;
};


// מחלקת אב של טופס הזמנה
class BookingForm {


    /*========== my code ====================================
    =========================================================*/
protected:
    std::vector <std::unique_ptr<AbstractField>> m_fields;



    //========================================================

    std::vector<std::string> fieldLabels; // תווית שדה
    std::vector<std::string> userInput; //  תווית שדה הזנה משתמש
    std::size_t activeField = 0; // מספר שדה פעיל
    sf::Clock cursorTimer;
    bool showCursor = true; // הצג סמן

    sf::RenderWindow& window; // חלון הזנת נתונים
    DialogueManager* formManager; // מצביע מטיפוס מנהל טופס
    PersonalInfo personalInfo; // מידע אישי

    virtual void setDefaultValues()=0 ; // פונקציה ו
    void openConfirmationWindow();

public:
    BookingForm(sf::RenderWindow& win, DialogueManager* manager);
    virtual ~BookingForm() = default;
    virtual std::string getFormType() const = 0;
    virtual void render(sf::RenderWindow& window) = 0;
    virtual void handleInput(sf::Event event) = 0;
};

#endif // BOOKINGFORM_H
