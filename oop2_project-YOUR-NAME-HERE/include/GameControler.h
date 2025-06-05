#pragma once
#include "GameMenu/MenuManager.h"

class GameControler {

public:
    GameControler();

    void runGeometryDash();

private:
    sf::RenderWindow m_window;
    MenuManager m_menuManager;
};
