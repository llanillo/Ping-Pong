#include "Actor/Ball/Ball.h"

Ball::Ball(float startX, float startY) {
    SetPosition(sf::Vector2f(startX, startY));
    SetRectangleShapePosition(GetPosition());
    SetRectangleShapeSize(sf::Vector2f(20, 20));
}

void Ball::ReboundSides()
{
    _directionX = -_directionX;
}

void Ball::ReboundBat(int score)
{
    _directionY = -_directionY;

	if (score % 5 == 0 && _speedCount > 0) {
        _speed *= 1.1f;
		_speedCount--;
	}
}

void Ball::ReboundTop()
{
    _directionY = -_directionY;
}

void Ball::ReboundBottom()
{
    SetPosition(sf::Vector2f(GetPosition().x, 20));
    _directionY = -_directionY;
}

void Ball::Update(const sf::Time& deltaTime)
{
    SetPosition(sf::Vector2f(GetPosition().x + _directionX * _speed * deltaTime.asSeconds(),
                             GetPosition().y + _directionY * _speed * deltaTime.asSeconds()));
    SetRectangleShapePosition(GetPosition());
}

void Ball::RestartBall()
{
    SetPosition(sf::Vector2f(1400 / 2.0f, 50));
    _speedCount = 6;
    _speed = 2000;
    SetRectangleShapePosition(GetPosition());
}