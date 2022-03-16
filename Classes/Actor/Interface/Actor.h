#ifndef PING_PONG_ACTOR_H
#define PING_PONG_ACTOR_H

#include "SFML/Graphics.hpp"

class Actor {

    sf::Vector2f Position;
    sf::RectangleShape RectangleShape;

public:

    virtual ~Actor() = default;

    virtual void Update(const sf::Time& deltaTime) = 0;

    sf::FloatRect GetShapePosition() const { return RectangleShape.getGlobalBounds(); };
    const sf::RectangleShape& GetShape() const { return RectangleShape; };
    const sf::Vector2f& GetPosition() const { return Position; };

    void SetPosition(const sf::Vector2f &position) { Position.x = position.x; Position.y = position.y; }
    void SetRectangleShapePosition(const sf::Vector2f &position) { RectangleShape.setPosition(position); };
    void SetRectangleShapeSize(const sf::Vector2f& size){ RectangleShape.setSize(size); };
};


#endif //PING_PONG_ACTOR_H
