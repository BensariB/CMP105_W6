#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;

	// initialise game objects
	textBall.loadFromFile("gfx/Beach_Ball.png");
	ball.setTexture(&textBall);
	ball.setPosition(sf::Vector2f(600, 0));
	ball.setSize(sf::Vector2f(100, 100));
}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{
	ball.setInput(input);
	ball.handleInput(dt);
	if (input->isKeyDown(sf::Keyboard::Escape)) {
		window->close();
	}
}

// Update game objects
void Level::update(float dt)
{
	ball.update_velocity(dt, window);
}

// Render level
void Level::render()
{
	beginDraw();
	window->draw(ball);
	endDraw();
}

// Begins rendering to the back buffer. Background colour set to light blue.
void Level::beginDraw()
{
	window->clear(sf::Color(100, 149, 237));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{
	window->display();
}