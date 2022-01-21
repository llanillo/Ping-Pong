#include <iostream>
#include <sstream>
#include "Bat.h"
#include "Ball.h"
#include <cstdlib>
#include <SFML/Graphics.hpp>

void handlePlayerInput(Bat& bat);
void handleBatCollision(Bat& bat, sf::Window& window, sf::Time& deltaTime);
void handleBallCollision(Ball& ball, Bat& bat, sf::Window& window, sf::Time& deltaTime, int& score, int& lives);

int main()
{
	const std::string welcomeStr = "Press Enter to Play";

	int score = 0;
	int lives = 3;

	bool paused = true;

	// Create videomode
	sf::VideoMode videoMode(1920, 1080);

	//Create and open window
	sf::RenderWindow window(videoMode, "Pong", sf::Style::Fullscreen);	

	// Create a bat at the bottom center of the screen
	Bat bat(1920 / 2.0f, 1050);

	// Create a ball
	Ball ball(1500 / 2.0f, 30);

	// Time
	sf::Clock clock;

	// Create HUD text
	sf::Text hud;
	sf::Text welcomeText;
	sf::FloatRect welcomeRect = welcomeText.getLocalBounds();
	welcomeText.setOrigin(welcomeRect.left + welcomeRect.width / 2.0f, welcomeRect.top + welcomeRect.height / 2.0f);
	welcomeText.setString(welcomeStr);

	// Retro style font
	sf::Font font;
	font.loadFromFile("fonts/Rubik-Black.ttf");

	hud.setFont(font);
	hud.setCharacterSize(75);
	hud.setFillColor(sf::Color::White);
	hud.setPosition(20, 20);

	welcomeText.setFont(font);
	welcomeText.setCharacterSize(100);
	welcomeText.setFillColor(sf::Color::White);
	welcomeText.setPosition(1020 / 2.0f, 1080 / 2.0f);

	sf::Event event;

	while (window.isOpen()) {		

		// Handle events
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			window.close();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return)) {
			paused = false;
		}

		if (!paused) {

			sf::Time deltaTime = clock.restart();
			handleBallCollision(ball, bat, window, deltaTime, score, lives);
			handleBatCollision(bat, window, deltaTime);
			handlePlayerInput(bat);


			if (lives < 1) {
				ball.restartBall();
				bat.restartBat();
				score = 0;
				lives = 3;
				paused = true;
			}
		}
		
		std::stringstream ss;
		ss << "Score: " << score << "  Lives: " << lives;
		hud.setString(ss.str());

		window.clear();
		window.draw(hud);
		window.draw(bat.getShape());
		window.draw(ball.getShape());

		if (paused) {
			window.draw(welcomeText);
		}

		window.display();
	}

	return 0;
}

void handlePlayerInput(Bat& bat) {
	// Handle player pressing and realising input
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		bat.moveLeft();
	}
	else {
		bat.stopLeft();
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		bat.moveRight();
	}
	else {
		bat.stopRight();
	}
}

void handleBallCollision(Ball& ball, Bat& bat, sf::Window& window, sf::Time& deltaTime, int& score, int& lives) {

	ball.update(deltaTime);

	// Handle the ball hitting bottom
	if (ball.getShapePosition().top > window.getSize().y) {

		ball.reboundBottom();
		lives--;
	}

	// Handle the ball hitting top
	if (ball.getShapePosition().top < 0) {
		ball.reboundTop();
	}

	// Handle the ball hitting sides
	if (ball.getShapePosition().left < 0 || ball.getShapePosition().left + ball.getShapePosition().width > window.getSize().x) {
		ball.reboundSides();
	}

	// Handle the ball hitting the bat
	if (ball.getShapePosition().intersects(bat.getShapePosition())) {
		// Reverse the ball and score
		ball.reboundBat(score);
		bat.ballCollision(score);

		score++;
	}

	// Restart the ball if its off screen
	if (ball.getPosition().x < -100 || ball.getPosition().x > 1920 ||ball.getPosition().y < -100 || ball.getPosition().y > 1080) {
		ball.restartBall();
	}
}

void handleBatCollision(Bat& bat, sf::Window& window, sf::Time& deltaTime) {
	bat.update(deltaTime);

	// Handle bat hitting sides
	if (bat.getShapePosition().left < 0) {
		bat.setPosition(sf::Vector2f(1500, bat.getPosition().y));
	}
	else if (bat.getShapePosition().left + bat.getShapePosition().width > window.getSize().x) {
		bat.setPosition(sf::Vector2f(50, bat.getPosition().y));
	}
}