#include "GrSprite.h"
#include <iostream>

void GrSprite::update_velocity(float dt, sf::RenderWindow* hwnd)
{
	move(getVelocity() * dt);
	//v = u + at
	if (getPosition().y + getSize().y >= hwnd->getSize().y) {
		setVelocity(getVelocity().x, getVelocity().y * (-0.5f));
	}
	else {
		setVelocity(getVelocity().x, getVelocity().y + acceleration * dt);
	}
}

void GrSprite::handleInput(float dt)
{
	if (input->isKeyDown(sf::Keyboard::Space)) {
		setVelocity(getVelocity().x, -300);
		input->setKeyUp(sf::Keyboard::Space);
	}
	if (input->isKeyDown(sf::Keyboard::Right)) {
		setVelocity(100 * dt, getVelocity().y);
	}
	if (input->isKeyDown(sf::Keyboard::Left)) {
		setVelocity(-100 * dt, getVelocity().y);
	}
	if (input->isMouseLDown()) {
		setVelocity(0, 0);
		setPosition(input->getMouseX(), input->getMouseY());
	}
}
