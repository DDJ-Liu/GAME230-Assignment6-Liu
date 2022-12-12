#include "Ball.h"

using namespace gm;
using namespace sf;

Ball::Ball(const sf::Vector2f position, const float size, const float speed):GameObject(position,Vector2f(2*size,2*size)) {
	body.setPosition(position);
	body.setRadius(size);
	body.setFillColor(Color::Green);
	protectTimer = 0;
}
void Ball::update(sf::RenderWindow& window, float deltatime) {
	//move ball
	if (protectTimer > 0) {
//		std::cout << protectTimer << std::endl;
		protectTimer -= deltatime;
	}
	move(velocity * deltatime);
	//hit wall
	//	bounceAtWall(hitBorder(window));
	//hit paddle
}
void Ball::render(sf::RenderWindow& window, float deltatime) {
	window.draw(body);
}
void Ball::setPosition(const sf::Vector2f& position) {
	//
	GameObject::setPosition(position);
	body.setPosition(position);
}
void Ball::move(const sf::Vector2f& velocity) {
	//std::cout << "ball move" << std::endl;
	GameObject::move(velocity);
	body.setPosition(position);
}
Vector2f Ball::getVelocity() const {
	return velocity;
}
void Ball::setVelocity(const sf::Vector2f& velocity) {
	this->velocity = velocity;
}
void Ball::bounceAtWall(Border border) {
	if (protectTimer <= 0) {
		switch (border)
		{
		case gm::NoBorder:
			return;
		case gm::LeftBorder:
			//		std::cout << "Left Wall bounce" << std::endl;
		case gm::RightBorder:
			//		std::cout << "Right Wall bounce" << std::endl;
			velocity.x *= -1;
			protectTimer = protectTime;
			return;
		case gm::BottomBorder:
			//		std::cout << "Bottom Wall bounce" << std::endl;
		case gm::TopBorder:
			//		std::cout << "Top Wall bounce" << std::endl;
			velocity.y *= -1;
			protectTimer = protectTime;
			return;
		default:
			std::cout << "Wall bounce error" << std::endl;
			break;
		}
	}
}
void Ball::bounceAtPeddal(const Paddle& paddle) {
	switch (paddle.getBorder())
	{
	case LeftBorder:
	case RightBorder:
		velocity.x *= -(1 + VELOCITY_AMPLIFIER);
		if (paddle.getMovementDirection() == Up) {
			velocity.y -= VELOCITY_FIXED_CHANGE_AMOUNT;
		}
		else if (paddle.getMovementDirection() == Down) {
			velocity.y += VELOCITY_FIXED_CHANGE_AMOUNT;
		}
		break;
	case BottomBorder:
	case TopBorder:
		velocity.y *= -(1 + VELOCITY_AMPLIFIER);
		if (paddle.getMovementDirection() == Left) {
			velocity.x -= VELOCITY_FIXED_CHANGE_AMOUNT;
		}
		else if (paddle.getMovementDirection() == Right) {
			velocity.x += VELOCITY_FIXED_CHANGE_AMOUNT;
		}
		break;
	default:
		break;
	}

}
const sf::Color& Ball::getFillColor() const {
	return body.getFillColor();
}
void Ball::setFillColor(const sf::Color& color) {
	body.setFillColor(color);
}
//TODO: reset to stick to the paddle
void Ball::reset(RenderWindow& window) {

	velocity.y = -originalSpeedPerSecond;
	velocity.x = Randf(-2 * originalSpeedPerSecond, 2 * originalSpeedPerSecond);
}

Border Ball::hitBorder(const RenderWindow& window) {
	int width = window.getSize().x;
	int height = window.getSize().y;
	if (position.x <= 0) {
		return LeftBorder;
	}
	if (position.y <= 0) {
		return TopBorder;
	}
	if (position.x + body.getRadius() * 2 >= width) {
		return RightBorder;
	}
	if (position.y + body.getRadius() * 2 >= height) {
		return BottomBorder;
	}
	return NoBorder;
}

void Ball::stickTo(Paddle& paddle) {
	setPosition(paddle.getPosition() + Vector2f(paddle.getSize().x / 2 - body.getRadius(), -2 * body.getRadius()));
}

Border Ball::hitBrick(Brick& brick) {
	if (protectTimer > 0) {
		return NoBorder;
	}
	if (brick.takeDamage()||!brick.breakable()) {
		//std::cout << "1" << std::endl;
		protectTimer = protectTime;
		float r = body.getRadius();
		float ballX = position.x + r;
		float ballY = position.y + r;
		Vector2f brickPos = brick.getPosition();

		if (ballY <= brickPos.y &&
			((brickPos.x - ballX) <= (brickPos.y - ballY)) &&
			((ballX - brickPos.x - BRICK_WIDTH) <= (brickPos.y - ballY))) {
//			std::cout << "1" << std::endl;
			return TopBorder;
		}
		if (ballY >= (brickPos.y+ BRICK_HEIGHT) &&
			((brickPos.x - ballX) <= (ballY - brickPos.y - BRICK_HEIGHT)) &&
			((ballX - brickPos.x - BRICK_WIDTH) <= (ballY - brickPos.y - BRICK_HEIGHT))) {
//			std::cout << "2" << std::endl;
			return BottomBorder;
		}
		if (ballX <= brickPos.x &&
			((brickPos.x - ballX) > (brickPos.y - ballY)) &&
			((brickPos.x - ballX) > (ballY - brickPos.y - BRICK_HEIGHT))) {
//			std::cout << "3" << std::endl;
			return LeftBorder;
		}
		if (ballX >= (brickPos.x + BRICK_WIDTH) &&
			((ballX - brickPos.x - BRICK_WIDTH) > (brickPos.y - ballY)) &&
			((ballX - brickPos.x - BRICK_WIDTH) > (ballY - brickPos.y - BRICK_HEIGHT))) {
//			std::cout << "4" << std::endl;
			return RightBorder;
		}
		/*
		if (ballX + r >= brickPos.x &&
			ballX - r <= brickPos.x + BRICK_WIDTH) {
			if (ballY + r >= brickPos.y &&
				ballY + r < brickPos.y + BRICK_HEIGHT) {
				return TopBorder;
			}
			if (ballY - r <= brickPos.y + BRICK_HEIGHT &&
				ballY - r > brickPos.y) {
				return BottomBorder;
			}
		}
		//std::cout << "2" << std::endl;
		if (ballY + r >= brickPos.y &&
			ballY - r <= brickPos.y + BRICK_HEIGHT) {
			if (ballX + r >= brickPos.x &&
				ballX + r < brickPos.x + BRICK_WIDTH) {
				return LeftBorder;
			}
			if (ballX - r <= brickPos.x + BRICK_WIDTH &&
				ballX - r > brickPos.x) {
				return RightBorder;
			}
		}
		*/
	}
	return NoBorder;
}

bool Ball::bounceAtBrick(Border border) {
	switch (border)
	{
	case gm::NoBorder:
		return false;
	case gm::LeftBorder:
	case gm::RightBorder:
		velocity.x *= -1;
		return true;
	case gm::BottomBorder:
	case gm::TopBorder:
		velocity.y *= -1;
		return true;
	default:
		std::cout << "Wall bounce error" << std::endl;
		break;
	}
	return false;
}



Ball::~Ball() {

}
