#include "Level.h"

using namespace gm;
using namespace sf;

Level::Level(){}

void Level::loadLevel(const int level[BRICKS_COUNT_Y][BRICKS_COUNT_X]) {
	for (int i = 0; i < BRICKS_COUNT_Y; i++) {
		for (int j = 0; j < BRICKS_COUNT_X; j++) {
			if (level[i][j] == 0) {
				bricks[i][j] = Brick(Brick::empty, Vector2f(BRICK_WIDTH * j, BRICK_HEIGHT * i), Vector2f(BRICK_WIDTH, BRICK_HEIGHT));
			}
			if (level[i][j] == 1) {
				bricks[i][j] = Brick(Brick::normBrick, Vector2f(BRICK_WIDTH * j, BRICK_HEIGHT * i), Vector2f(BRICK_WIDTH, BRICK_HEIGHT));
			}
			if (level[i][j] == 2) {
				bricks[i][j] = Brick(Brick::hardBrick, Vector2f(BRICK_WIDTH * j, BRICK_HEIGHT * i), Vector2f(BRICK_WIDTH, BRICK_HEIGHT));
			}
			if (level[i][j] == 3) {
				bricks[i][j] = Brick(Brick::undestructible, Vector2f(BRICK_WIDTH * j, BRICK_HEIGHT * i), Vector2f(BRICK_WIDTH, BRICK_HEIGHT));
			}
		}
	}
}

void Level::update(sf::RenderWindow& window, float deltaTime) {
	for (int i = 0; i < BRICKS_COUNT_Y; i++) {
		for (int j = 0; j < BRICKS_COUNT_X; j++) {
			bricks[i][j].update(window, deltaTime);
		}
	}
}

void Level::render(sf::RenderWindow& window, float deltaTime) {
	for (int i = 0; i < BRICKS_COUNT_Y; i++) {
		for (int j = 0; j < BRICKS_COUNT_X; j++) {
			bricks[i][j].render(window, deltaTime);
		}
	}
}

bool Level::handleCollide(Ball& ball, SoundManager& soundManager) {
	for (int i = 0; i < BRICKS_COUNT_Y; i++) {
		for (int j = 0; j < BRICKS_COUNT_X; j++) {
			if (ball.collide(bricks[i][j].getCollider())) {
				if (ball.bounceAtBrick(ball.hitBrick(bricks[i][j]))) {
					if (bricks[i][j].breakable()) {
						if (bricks[i][j].getHp() == 0) {
							soundManager.playSFX(SoundManager::BreakBrick);
						}
						else {
							soundManager.playSFX(SoundManager::HitBrick);
						}
						return true;
					}
					else {
						soundManager.playSFX(SoundManager::UnbreakableBrick);
						return false;
					}
				}
			}
		}
	}
	return false;
}

bool Level::isClear() {
	for (int i = 0; i < BRICKS_COUNT_Y; i++) {
		for (int j = 0; j < BRICKS_COUNT_X; j++) {
			if ((bricks[i][j].getHp() > 0) && bricks[i][j].breakable())
				return false;
		}
	}
	return true;
}

Level::~Level() {

}
