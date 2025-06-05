#pragma once
#include "GameMenu/TypeButton.h"
#include "iostream"
#include <vector>

class ImagesButton {
public:
    static void loadAllTextures();
    static sf::Sprite getSpinte(const TypeButton& type, const sf::Vector2f& wantedSize);


private:
    static std::vector<sf::Texture> m_pictures;


    //static void loadStart();
    //static void loadStore();
    //static void loadHelp();
    //static void loadExit();
};
