#ifndef PING_PONG_INPUTMANAGER_H
#define PING_PONG_INPUTMANAGER_H

#include "SFML/Graphics.hpp"

class InputManager {

    bool _movingRight = false;
    bool _movingLeft = false;

public:

    void HandleInput();

    const bool& GetMovingRight() const{ return _movingRight; };
    const bool& GetMovingLeft() const { return _movingLeft; };
};


#endif
