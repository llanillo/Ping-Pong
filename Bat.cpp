#include "Bat.h"

Bat::Bat(float startX, float startY) {
	position.x = startX;
	position.y = startY;

	shape.setSize(sf::Vector2f(initialWidth, initialHeight));
	shape.setPosition(position);
}


sf::FloatRect Bat::getShapePosition()
{
	return shape.getGlobalBounds();
}

sf::Vector2f Bat::getPosition()
{
	return position;
}

sf::RectangleShape Bat::getShape()
{
	return shape;
}

void Bat::setPosition(sf::Vector2f vector2f)
{
	position.x = vector2f.x;
	position.y = vector2f.y;
	shape.setPosition(vector2f);
}

void Bat::moveLeft()
{
	movingLeft = true;
}

void Bat::moveRight()
{
	movingRight = true;
}

void Bat::stopLeft()
{
	movingLeft = false;
}

void Bat::stopRight()
{
	movingRight = false;
}

void Bat::update(sf::Time deltaTime)
{
	if (movingLeft) {
		position.x -= speed * deltaTime.asSeconds();
	}
	else if (movingRight) {
		position.x += speed * deltaTime.asSeconds();
	}

	shape.setPosition(position);
}

void Bat::ballCollision(int score)
{
	if (score % 5 == 0 && initialDecreaseCount > 0) {
		width *= deacreasePercent;
		shape.setSize(sf::Vector2f(initialWidth, initialHeight));
		decreaseCount--;
	}
}

void Bat::restartBat()
{
	width = initialWidth;
	decreaseCount = initialDecreaseCount;
}
