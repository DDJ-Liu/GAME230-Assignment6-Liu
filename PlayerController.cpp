#include "PlayerController.h"

using namespace gm;
using namespace sf;

PlayerController::PlayerController(int id, Paddle& p, PaddleDirection pd) :Controller(id, p, pd) {

}
PlayerController::PlayerController() {

}

PlayerController::~PlayerController() {
	paddle = nullptr;
}
void PlayerController::update(sf::RenderWindow& window, float deltaTime) {
	if (Mouse::getPosition(window).x < (paddle->getPosition().x + PADDLE_LENGTH / 2 - MOUSE_CONTROL_TOLERANCE)) {
		paddle->setMovmentDirection(Left);
	}
	else if (Mouse::getPosition(window).x > (paddle->getPosition().x + PADDLE_LENGTH / 2 + MOUSE_CONTROL_TOLERANCE)) {
		paddle->setMovmentDirection(Right);
	}
	else {
		paddle->setMovmentDirection(None);
	}
	paddle->update(window, deltaTime);
}

void PlayerController::handleInput(sf::RenderWindow& window, Event event) {
	if (Mouse::getPosition(window).x < (paddle->getPosition().x + PADDLE_LENGTH / 2 - MOUSE_CONTROL_TOLERANCE)) {
		paddle->setMovmentDirection(Left);
	}
	else if (Mouse::getPosition(window).x > (paddle->getPosition().x + PADDLE_LENGTH / 2 + MOUSE_CONTROL_TOLERANCE)) {
		paddle->setMovmentDirection(Right);
	}
	else {
		paddle->setMovmentDirection(None);
	}

/*
	if (event.type == Event::KeyPressed) {
		if (event.key.code == key1) {
			if (direction == horizontal) {
				paddle->setMovmentDirection(MovementDirection::Left);
			}
			else {
				paddle->setMovmentDirection(MovementDirection::Up);
			}
		}
		else if (event.key.code == key2) {
			if (direction == horizontal) {
				paddle->setMovmentDirection(MovementDirection::Right);
			}
			else {
				paddle->setMovmentDirection(MovementDirection::Down);
			}
		}
	}

	if (event.type == Event::KeyReleased) {
		if (event.key.code == key1 && (paddle->getMovementDirection() == MovementDirection::Left || paddle->getMovementDirection() == MovementDirection::Up)) {
			paddle->setMovmentDirection(MovementDirection::None);
		}
		if (event.key.code == key2 && (paddle->getMovementDirection() == MovementDirection::Right || paddle->getMovementDirection() == MovementDirection::Down)) {
			paddle->setMovmentDirection(MovementDirection::None);
		}
	}
	*/
}