#include "Bat.h"

Bat::Bat(float startX, float startY) {
    SetPosition(sf::Vector2f(startX, startY));
    SetRectangleShapePosition(GetPosition());
    SetRectangleShapeSize(sf::Vector2f(InitialWidth, InitialHeight));
}

void Bat::MoveLeft()
{
    _movingLeft = true;
}

void Bat::MoveRight()
{
    _movingRight = true;
}

void Bat::StopLeft()
{
    _movingLeft = false;
}

void Bat::StopRight()
{
    _movingRight = false;
}

void Bat::BallCollision(int score)
{
	if (score % 5 == 0 && InitialSpeedLevels > 0) {
        _width *= WidthDecreasePercent;
        SetRectangleShapeSize(sf::Vector2f(InitialWidth, InitialHeight));
		_speedLevel--;
	}
}

void Bat::RestartBat()
{
    _width = InitialWidth;
    _speedLevel = InitialSpeedLevels;
}

void Bat::Update(const sf::Time &deltaTime) {
    if (_movingLeft) {
        SetPosition(sf::Vector2f(GetPosition().x - MovementSpeed * deltaTime.asSeconds(), GetPosition().y));
    }
    else if (_movingRight) {
        SetPosition(sf::Vector2f(GetPosition().x + MovementSpeed * deltaTime.asSeconds(), GetPosition().y));
    }

    SetRectangleShapePosition(GetPosition());
}
