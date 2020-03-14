#include "Ball.h"
#include <math.h>
#include <vector>

class RainManager
{
public:
	RainManager();
	~RainManager();
	void spawn(int);
	void update(float dt,int);
	void deathCheck(int);
	void render(sf::RenderWindow* window);

private:
	std::vector<Ball> drops;
	sf::Vector2f spawnPoint;
	sf::Texture texture;
};

