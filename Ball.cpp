#include "Ball.h"

Ball::Ball(float startX, float startY) {
	position.x = startX;
	position.y = startY;

	shape.setSize(sf::Vector2f(20, 20));
	shape.setPosition(position);
}

sf::FloatRect Ball::getShapePosition()
{
	return shape.getGlobalBounds();
}

sf::Vector2f Ball::getPosition()
{
	return position;
}

sf::RectangleShape Ball::getShape()
{
	return shape;
}

float Ball::getXVelocity()
{
	return directionX;
}

void Ball::reboundSides()
{
	directionX = -directionX;
}

void Ball::reboundBat(int score)
{
	directionY = -directionY;

	if (score % 5 == 0 && speedIncreaseCount > 0) {
		speed *= 1.1f;
		speedIncreaseCount--;
	}
}

void Ball::reboundTop()
{
	directionY = -directionY;
}

void Ball::reboundBottom()
{
	position.y = 20;
	directionY = -directionY;
}

void Ball::update(sf::Time deltaTime)
{
	position.y += directionY * speed * deltaTime.asSeconds();
	position.x += directionX * speed * deltaTime.asSeconds();

	shape.setPosition(position);
}

void Ball::restartBall()
{
	position.x = 1400 / 2.0f;
	position.y = 30;
	speedIncreaseCount = 6;
	speed = 2000;
	shape.setPosition(position);
}
