#include "MovingSprite.h"

MovingSprite::MovingSprite()
{
	target = sf::Vector2f(1000, 600);
	speed = 40.f;
	acceleration = 50.f;
}

MovingSprite::~MovingSprite()
{

}

void MovingSprite::handleInput(float dt)
{
	target = sf::Vector2f(input->getMouseX(), input->getMouseY());
}

void MovingSprite::update(float dt)
{
	direction = target - getPosition();
	direction = Vector::normalise(direction);
	velocity += direction * acceleration * dt;
	move(velocity * dt);

	if(Vector::magnitude(target -getPosition()) < 100.f){
		//setPosition(target);
		velocity = sf::Vector2f(0, 0);
	}
}
