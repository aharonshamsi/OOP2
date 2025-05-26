#pragma once
#include <string>
#include <SFML/Graphics.hpp>

namespace GameConsts {
    
    inline const std::string NAME_GAME = "Game Xonix"; // name of the game window
    inline const std::string NAME_ERROR = "Error Window"; // name of the error window
    inline const std::string NAME_FLAYLIST_LEVEL = "playlistLevels.txt"; // filename for level playlist
    inline const std::string NAME_FILE_IMAGE_BACKGROUND = "background.png"; // background game
    inline const std::string NAME_FILE_IMAGE_FINISH = "finishGame.png"; // background game
        
    inline const float HIGHT_SHAPE_INFO = 100.f; // height of the info panel

    extern const sf::Color COLOR_SHAPE_INFO; // color of the info rectangle
    extern const sf::Color COLOR_TEXT_INFO;  // color of the info text

    extern const unsigned int SIZE_CHARACTER; // font size
    extern const unsigned int POINTS_PER_TILE; // points per tile factor
    extern const unsigned int OVER_CAPTURE_BONUS; // bonus factor for over 10% capture

    extern sf::Vector2f sizeTile; // tile size
}
