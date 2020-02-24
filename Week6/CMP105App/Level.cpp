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

	kinball.setTexture(&textBall);
	kinball.setPosition(sf::Vector2f(600, 600));
	kinball.setSize(sf::Vector2f(100, 100));

	cball.setFillColor(sf::Color::Blue);
	cball.setOutlineColor(sf::Color::White);
	cball.setOutlineThickness(2.f);
	cball.setPosition(sf::Vector2f(300, 300));
	cball.setRadius(15);
}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{
	//ball.setInput(input);
	//ball.handleInput(dt);

	kinball.setInput(input);
	kinball.handleInput(dt);

	cannon.setInput(input);
	cannon.handleInput(dt);
	if (input->isKeyDown(sf::Keyboard::Escape)) {
		window->close();
	}
}

// Update game objects
void Level::update(float dt)
{
	ball.update_velocity(dt, window);
	kinball.update(dt);

	cannon.update(dt);
	cball.setPosition(cannon.getPosition());
}

// Render level
void Level::render()
{
	beginDraw();
	window->draw(ball);
	window->draw(kinball);
	window->draw(cball);
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