#include "Brick.h"

using namespace gm;
using namespace sf;

Brick::Brick(BrickType type, const sf::Vector2f& position, const sf::Vector2f& size):Box(position,size) {
	body.setOutlineThickness(-1);
	switch (type)
	{
	case gm::Brick::normBrick:
		hp = 1;
		destructible = true;
		body.setFillColor(BRICK_FILL_COLOR[hp]);
		body.setOutlineColor(BRICK_OUTLINE_COLOR[hp]);
		break;
	case gm::Brick::hardBrick:
		hp = 2;
		destructible = true;
		body.setFillColor(BRICK_FILL_COLOR[hp]);
		body.setOutlineColor(BRICK_OUTLINE_COLOR[hp]);
		break;
	case gm::Brick::undestructible:
		hp = 9999;
		destructible = false;
		body.setFillColor(BRICK_FILL_COLOR[undestructible]);
		body.setOutlineColor(BRICK_OUTLINE_COLOR[undestructible]);
		break;
	case gm::Brick::empty:
		hp = 0;
		destructible = true;
		body.setFillColor(BRICK_FILL_COLOR[hp]);
		body.setOutlineColor(BRICK_OUTLINE_COLOR[hp]);
		break;
	default:
		break;
	}
}

Brick::Brick(){

}

bool Brick::takeDamage() {
	if (destructible && hp > 0) {
		hp--;
		if (hp <= 2) {
			body.setFillColor(BRICK_FILL_COLOR[hp]);
			body.setOutlineColor(BRICK_OUTLINE_COLOR[hp]);
		}
		return true;
	}
	return false;
}

void Brick::update(sf::RenderWindow& window, float deltaTime) {
	Box::update(window, deltaTime);
}

void Brick::render(sf::RenderWindow& window, float deltaTime) {
	Box::render(window, deltaTime);
}

bool Brick::breakable()const {
	return destructible;
}

int Brick::getHp()const {
	return hp;
}


Brick::~Brick(){

}
