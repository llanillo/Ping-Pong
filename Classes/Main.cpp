#include <iostream>
#include <sstream>

#include <SFML/Graphics.hpp>
#include "Actor/Ball/Ball.h"
#include "Actor/Player/Bat/Bat.h"

void HandlePlayerInput(Bat& bat);
void HandleBatCollision(Bat& bat, const sf::Window& window, const sf::Time& deltaTime);
void HandleBallCollision(Ball& ball, Bat& bat, const sf::Window& window, const sf::Time& deltaTime, int& score, int& lives);

int main()
{
	const std::string welcomeStr = "Press Enter to Play";

	int score = 0;
	int lives = 3;

	bool paused = true;

	// Create video-mode
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
    font.loadFromFile("../Fonts/Rubik-Black.ttf");

	hud.setFont(font);
	hud.setCharacterSize(75);
	hud.setFillColor(sf::Color::White);
	hud.setPosition(20, 20);

	welcomeText.setFont(font);
	welcomeText.setCharacterSize(100);
	welcomeText.setFillColor(sf::Color::White);
	welcomeText.setPosition(1020 / 2.0f, 1080 / 2.0f);

	sf::Event event{};

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
            HandleBallCollision(ball, bat, window, deltaTime, score, lives);
            HandleBatCollision(bat, window, deltaTime);
            HandlePlayerInput(bat);


			if (lives < 1) {
                ball.RestartBall();
                bat.RestartBat();
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
		window.draw(bat.GetShape());
		window.draw(ball.GetShape());

		if (paused) {
			window.draw(welcomeText);
		}

		window.display();
	}

	return 0;
}

void HandlePlayerInput(Bat& bat) {
	// Handle player pressing and realising input
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        bat.MoveLeft();
	}
	else {
        bat.StopLeft();
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        bat.MoveRight();
	}
	else {
        bat.StopRight();
	}
}

void HandleBallCollision(Ball& ball, Bat& bat, const sf::Window& window, const sf::Time& deltaTime, int& score, int& lives) {

    ball.Update(deltaTime);

	// Handle the ball hitting bottom
	if (ball.GetShapePosition().top > (float) window.getSize().y) {

        ball.ReboundBottom();
		lives--;
	}

	// Handle the ball hitting top
	if (ball.GetShapePosition().top < 0) {
        ball.ReboundTop();
	}

	// Handle the ball hitting sides
	if (ball.GetShapePosition().left < 0 ||
            ball.GetShapePosition().left + ball.GetShapePosition().width > (float) window.getSize().x) {
        ball.ReboundSides();
	}

	// Handle the ball hitting the bat
	if (ball.GetShapePosition().intersects(bat.GetShapePosition())) {
		// Reverse the ball and score
        ball.ReboundBat(score);
        bat.BallCollision(score);

		score++;
	}

	// Restart the ball if its offscreen
	if (ball.GetPosition().x < -100 || ball.GetPosition().x > 1920 || ball.GetPosition().y < -100 ||
            ball.GetPosition().y > 1080) {
        ball.RestartBall();
	}
}

void HandleBatCollision(Bat& bat, const sf::Window& window, const sf::Time& deltaTime) {
    bat.Update(deltaTime);

	// Handle bat hitting sides
	if (bat.GetShapePosition().left < 0) {
        bat.SetPosition(sf::Vector2f(1500, bat.GetPosition().y));
	}
	else if (bat.GetShapePosition().left + bat.GetShapePosition().width > (float) window.getSize().x) {
        bat.SetPosition(sf::Vector2f(50, bat.GetPosition().y));
	}
}