#pragma once
#include <SFML/Graphics.hpp>

class Bat {
private:
	sf::Vector2f position;
	sf::RectangleShape shape;

	const float initialWidth = 350;
	const float initialHeight = 10;

	float width = initialWidth;

	const float speed = 1000.0f;
	const float deacreasePercent = 0.9f;

	const int initialDecreaseCount = 3;
	int decreaseCount = initialDecreaseCount;

	bool movingRight = false;
	bool movingLeft = false;

public:
	Bat(float startX, float startY);

	sf::FloatRect getShapePosition();
	sf::Vector2f getPosition();
	sf::RectangleShape getShape();

	void setPosition(sf::Vector2f vector2f);
	void moveLeft();
	void moveRight();
	void stopLeft();
	void stopRight();
	void update(sf::Time deltaTime);
	void ballCollision(int score);
	void restartBat();

};
