#include "Engine.h"

void Engine::Input() {
    sf::Event event{};

    while (_renderWindow.pollEvent(event)) {
        if (event.type == sf::Event::KeyPressed) {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
                _renderWindow.close();
            } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return)) {
                _isPlaying = true;
            }

            if (_isPlaying) {

            }
        }
    }
}

Engine::Engine() {
    sf::Vector2<unsigned int> resolution;
    resolution.y = sf::VideoMode::getDesktopMode().height;
    resolution.x = sf::VideoMode::getDesktopMode().width;

    _renderWindow.create(sf::VideoMode(1920, 1080), "Ping Pong", sf::Style::Fullscreen);

    _renderWindow.setSize(resolution);

    // Assign Background
    // TO DO
}

void Engine::Draw() {

}

void Engine::Run() {
    sf::Clock clock;

    while(_renderWindow.isOpen()) {
        sf::Time deltaTime = clock.restart();
        _totalGameTime += deltaTime;

        Update(deltaTime.asSeconds());
        Input();
        Draw();
    }

}

void Engine::Update(float deltaTime) {
    if (_isPlaying) {

    }
}
