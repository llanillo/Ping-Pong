#pragma once
#include <SFML/Graphics.hpp>
#include "../Interface/Actor.h"

class Bat : public Actor{

    const int InitialSpeedLevels = 3;

    const float WidthDecreasePercent = 0.9f;
    const float InitialWidth = 350;
    const float InitialHeight = 10;
    const float MovementSpeed = 1000.0f;
    int _speedLevel = InitialSpeedLevels;

    float _width = InitialWidth;
	bool _movingRight = false;
    bool _movingLeft = false;

public:

    Bat(float startX, float startY);

    void BallCollision(int score);
    void MoveLeft();
    void MoveRight();
    void StopLeft();
    void StopRight();
    void RestartBat();

    void Update(const sf::Time &deltaTime) override;
};
