#ifndef PING_PONG_ENGINE_H
#define PING_PONG_ENGINE_H

#include <SFML/Graphics.hpp>

class Engine {

    bool _isPlaying = false;

    sf::RenderWindow _renderWindow;
    sf::Sprite _backgroundSprite;
    sf::Texture _backgroundTexture;
    sf::Time _totalGameTime;

    void Input();
    void Update(float deltaTime);
    void Draw();

public:
    Engine();

    void Run();

};


#endif //PING_PONG_ENGINE_H
