#pragma once
#include <SFML/Graphics.hpp>

class Ball {
private:
	sf::Vector2f position;
	sf::RectangleShape shape;

	float speed = 2000.0f;
	float directionX = .2f;
	float directionY = .2f;

	int speedIncreaseCount = 6;

public:
	Ball(float startX, float startY);

	sf::FloatRect getShapePosition();
	sf::Vector2f getPosition();
	sf::RectangleShape getShape();

	float getXVelocity();

	void reboundSides();
	void reboundBat(int score);
	void reboundTop();
	void reboundBottom();
	void update(sf::Time deltaTime);
	void restartBall();
};