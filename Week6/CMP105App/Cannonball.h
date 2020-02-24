#pragma once
#include "Framework/GameObject.h"
#include "Framework/Vector.h"
class Cannonball: public GameObject
{
private:
	sf::Vector2f origin;
	sf::Vector2f mousepoint;
	sf::Vector2f magnit;
	bool shoot;
	bool press;
	float gravity;
public:
	Cannonball();
	~Cannonball();
	void handleInput(float dt);
	void update(float dt) override;
};

