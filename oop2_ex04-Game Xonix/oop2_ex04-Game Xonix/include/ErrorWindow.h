#pragma once
#include <SFML/Graphics.hpp>
#include "GameException.h"
#include "GameConsts.h"


class ErrorWindow {

public:
    ErrorWindow(const GameException exception);

    void display();

private:
    const GameException m_exception;
    sf::RenderWindow m_erroeWindow;
};
