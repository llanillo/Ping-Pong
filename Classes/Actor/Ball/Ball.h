#pragma once
#include <SFML/Graphics.hpp>
#include "../Interface/Actor.h"

class Ball : public Actor{
	float _speed = 2000.0f;
	float _directionX = .2f;
	float _directionY = .2f;
	int _speedCount = 6;

public:
	Ball(float startX, float startY);

    void ReboundSides();
    void ReboundBat(int score);
    void ReboundTop();
    void ReboundBottom();
    void RestartBall();

    float GetXVelocity() const { return _directionX; };

    void Update(const sf::Time &deltaTime) override;
};