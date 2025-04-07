#include "Engine.h"

Engine::Engine()
    : window(sf::VideoMode(500, 600), "Massive Travel Booking System"),
       uiManager(window, dialogueManager)  // ✅ Fix: Pass formManager
{
}
void Engine::run() {
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            uiManager.handleEvent(event);
        }

        dialogueManager.handleFormEvents();  // ✅ Ensures form window updates properly

        window.clear(sf::Color(240, 240, 240));
        uiManager.render();
        window.display();
    }
}

