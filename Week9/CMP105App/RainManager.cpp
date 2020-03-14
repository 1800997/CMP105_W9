#include "RainManager.h"

RainManager::RainManager()
{
	srand(time(NULL));

	texture.loadFromFile("gfx/Water.png");

	for (int i = 0; i < 40; i++)
	{
		drops.push_back(Ball());
		drops[i].setAlive(false);
		drops[i].setTexture(&texture);
		drops[i].setSize(sf::Vector2f(100, 100));
	}
};

RainManager::~RainManager()
{

};

void RainManager::update(float dt,int maxY)
{
	for (int i = 0; i < drops.size(); i++)
	{
		if (drops[i].isAlive())
		{
			drops[i].update(dt);
		}
	}
	deathCheck(maxY);
};

void RainManager::spawn(int maxX)
{
	for (int i = 0; i < drops.size(); i++)
	{
		if (!drops[i].isAlive())
		{
			if (rand() % 100 < 5)
			{
				spawnPoint = sf::Vector2f(rand() % maxX, 0);
				drops[i].setAlive(true);
				drops[i].setVelocity(0, 300);
				drops[i].setPosition(spawnPoint);
			}
			return;
		}
	}
};

void RainManager::deathCheck(int maxY)
{
	for (int i = 0; i < drops.size(); i++)
	{
		if (drops[i].isAlive())
		{
			if (drops[i].getPosition().y > maxY)
			{
				drops[i].setAlive(false);
			}
		}
	}
};

void RainManager::render(sf::RenderWindow* window)
{
	for (int i = 0; i < drops.size(); i++)
	{
		if (drops[i].isAlive())
		{
			window->draw(drops[i]);
		}
	}
};