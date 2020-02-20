#pragma once
#include "Framework/GameObject.h"
class GrSprite : public GameObject
{
public:
	void update_velocity(float dt, sf::RenderWindow* hwnd);
	void handleInput(float dt);

protected:
	float acceleration = 200.0f;
};

