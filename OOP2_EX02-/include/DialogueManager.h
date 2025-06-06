#ifndef DIALOGUEMANAGER_H
#define DIALOGUEMANAGER_H

#include "BookingForm.h"
#include <SFML/Graphics.hpp>
#include <memory>
#include <iostream>

// מנהל מילוי הטפסים
class DialogueManager {
private:
    std::unique_ptr<BookingForm> activeForm; // וקטור הטפסים
    sf::RenderWindow formWindow; // חלון מילוי הטופס
    bool isFormOpen; // הטופס שפתוח

public:
    DialogueManager();
    void setActiveForm(std::unique_ptr<BookingForm> form);
    void handleFormEvents();
    void closeForm();
};

#endif // DIALOGUEMANAGER_H
