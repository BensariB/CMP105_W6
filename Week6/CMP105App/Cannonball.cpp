#include "Cannonball.h"

Cannonball::Cannonball()
{
	origin = sf::Vector2f(300, 300);
	setPosition(sf::Vector2f(300, 300));
	shoot = 0;
	press = 0;
	gravity = 500.f;
}

Cannonball::~Cannonball()
{
}

void Cannonball::handleInput(float dt)
{
	if (input->isMouseLDown()) {
		mousepoint = sf::Vector2f(input->getMouseX(), input->getMouseY());
		shoot = 1;
	}
	if (shoot == 1 && input->isMouseLDown() == 0) {
		
		magnit = mousepoint - origin;
		magnit *= -1.f;
		velocity = (Vector::normalise(magnit));
		velocity *= 500.f;
		shoot = 0;
		press = 1;
	}
}

void Cannonball::update(float dt)
{
	if (press == 1) {
		setVelocity(getVelocity().x, getVelocity().y + gravity * dt);
		setPosition(getPosition() + (velocity * dt));
	}
}
