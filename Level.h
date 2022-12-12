#ifndef LEVEL_H
#define LEVEL_H

#include "Brick.h"
#include "Ball.h"
#include "SoundManager.h"

namespace gm {
	class Level
	{
	private:
		Brick bricks[BRICKS_COUNT_Y][BRICKS_COUNT_X];
	public:
		Level();
		void loadLevel(const int level[BRICKS_COUNT_Y][BRICKS_COUNT_X]);
		void update(sf::RenderWindow& window, float deltaTime);
		void render(sf::RenderWindow& window, float deltaTime);
		bool handleCollide(Ball& ball,SoundManager& soundManager);
		bool isClear();
		~Level();
	};
}
#endif