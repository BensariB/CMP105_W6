#pragma once
#include "Framework/GameObject.h"
#include "Framework/Vector.h"
class MovingSprite : public GameObject
{
private:
	sf::Vector2f target;
	sf::Vector2f direction;
	float speed;
	float acceleration;
public:
	MovingSprite();
	~MovingSprite();
	void handleInput(float dt);
	void update(float dt);
};

