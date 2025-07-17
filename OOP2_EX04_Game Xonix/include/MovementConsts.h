#pragma once

namespace MovementConsts {
    inline const sf::Vector2f DIRECTION_UP = { 0, -1 };
    inline const sf::Vector2f DIRECTION_DOWN = { 0, 1 };
    inline const sf::Vector2f DIRECTION_LEFT = { -1, 0 };
    inline const sf::Vector2f DIRECTION_RIGHT = { 1, 0 };
    inline const sf::Vector2f NO_DIRECTION = { 0, 0 };

    inline const float MOVE_PIXEL_PLAYER = 180.f; // Speed ​​in pixels per second
    inline const float MOVE_PIXEL_ENEMY = 180.f; 
}
