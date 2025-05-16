#pragma once
#include "GameException.h"
#include <SFML/Graphics.hpp>


class ErrorWindow {

public:
public:
    ErrorWindow(const GameException exception);
 


    void display();

private:
    const GameException m_exception;
    sf::RenderWindow m_erroeWindow;
};
