#pragma once
#include <SFML/Graphics.hpp>
#include "GameObject/Images/TypeObject.h"


class ImagesObject {
public:
    ImagesObject();

    sf::Sprite getSpriteObject(const TypeObject& type) const;

private:
    static std::vector<sf::Texture> m_imagesObject;

    static void loadAllImages();
    static void loadImageSpriteSheet();


};