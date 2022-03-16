#include "InputManager.h"

void InputManager::HandleInput() {
//    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
//        _movingLeft = true;
//    }
//    else {
//        _movingLeft = false;
//    }
//    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
//        _movingRight = true;
//    }
//    else {
//        _movingRight = false;
//    }
    _movingLeft = sf::Keyboard::isKeyPressed(sf::Keyboard::Left);
    _movingRight = sf::Keyboard::isKeyPressed(sf::Keyboard::Right);
}
