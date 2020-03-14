#include "Level.h"


Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;

	// initialise game objects

	maxX = window->getSize().x;
	maxY = window->getSize().y;

}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{
	if (input->isKeyDown(sf::Keyboard::Space))
	{
		BallManager.spawn();
	}
	if (input->isKeyDown(sf::Keyboard::Down))
	{
		
		rain.spawn(maxX);
	}
}

// Update game objects
void Level::update(float dt)
{
	BallManager.update(dt);
	rain.update(dt, maxY);
}

// Render level
void Level::render()
{
	beginDraw();
	BallManager.render(window);
	rain.render(window);
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