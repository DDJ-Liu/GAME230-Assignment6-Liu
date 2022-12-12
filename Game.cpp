// We need to include our header file to implement the function prototypes of our Game class
#include "Game.h"


// Since we are in our private .cpp file, it's fine to use a namespace here
using namespace gm;
using namespace sf;

// Implement constructor, this will effectively be a setup function as the game gets more complex
Game::Game() : window(VideoMode(GameWidth, GameHeight), "Game"), clock(), deltaTime(0), ball(Vector2f(GameWidth / 2, GameHeight / 2))/*box1(Vector2f(250, 300), Vector2f(50, 50)), box2(Vector2f(350, 300), Vector2f(50, 50))*/ {
	// Set our fps to 60
	window.setFramerateLimit(60);
}

void Game::run() {
	// This is our game loop!
	// All input, logic, and rendering should be handled here
	initialize();
	while (window.isOpen())
	{
		// Every frame we...
		// Keep track of the delta time for smoother movement
		deltaTime = clock.restart().asSeconds();

		// Handle input first...
		handleInput();

		// Then update...
		update();

		// Then render...
		render();
	}
}

// Implements the handle input portion of our Game Loop Programming Pattern
void Game::handleInput() {
	// Check for events from the window
	// E.g., is the window being closed?
	Event event;
	while (window.pollEvent(event))
	{
		if (event.type == Event::Closed)
			window.close();

		if (gameState == start) {
			if (Mouse::isButtonPressed(Mouse::Left)) {
				gameState = running;
			}
		}


		//playerController.handleInput(window, event);

		/*
		// Handle keyboard input to move box 1
		if (event.type == Event::KeyPressed) {
			if (event.key.code == Keyboard::Left) {
				box1.setMovmentDirection(MovementDirection::Left);
			}else if (event.key.code == Keyboard::Right) {
				box1.setMovmentDirection(MovementDirection::Right);
			}
		}

		if (event.type == Event::KeyReleased) {
			if (event.key.code == Keyboard::Left && box1.getMovementDirection() == MovementDirection::Left) {
				box1.setMovmentDirection(MovementDirection::None);
			}
			if (event.key.code == Keyboard::Right && box1.getMovementDirection() == MovementDirection::Right) {
				box1.setMovmentDirection(MovementDirection::None);
			}
		}
		*/
	}
}

// Implements the update portion of our Game Loop Programming Pattern
void Game::update() {

	ball.update(window,deltaTime);
	playerController.update(window, deltaTime);

	if (gameState == start) {
		ball.stickTo(paddle);
	}
	if (gameState == running) {
		if (ball.hitBorder(window) != NoBorder) {
			if (ball.hitBorder(window) == BottomBorder) {
				if (life > 0) {
					//lose life
					life--;
					soundManager.playSFX(SoundManager::LoseHp);
					ball.reset(window);
					gameState = start;
					ui.updateHp(life);
				}
				else {
					//end game
					endGame();
				}
			}
			else {
				ball.bounceAtWall(ball.hitBorder(window));
				soundManager.playSFX(SoundManager::BounceWall);
			}
		}
		if (ball.collide(paddle.getCollider())) {
			ball.bounceAtPeddal(paddle);
			soundManager.playSFX(SoundManager::BouncePaddle);
		}
	}

	/*
	for (int i = 0; i < 3; i++) {
		bricks[i].update(window, deltaTime);
		if (ball.collide(bricks[i].getCollider())) {
			ball.bounceAtBrick(ball.hitBrick(bricks[i]));
		}
	}*/

	level.update(window, deltaTime);

	if (level.handleCollide(ball,soundManager)) {
		score += levelCount;
		ui.updateScore(score);
	}

	if (level.isClear()) {
		nextLevel();
	}

	// Update our boxes (i.e., move them based on the block's specified movement direction)
	/*
	box1.update(window, deltaTime);
	box2.update(window, deltaTime);

	// If the mouse has entered box 1 then color it green
	if (box1.collide(Vector2f(Mouse::getPosition(window)))) {
		box1.setFillColor(Color::Green);
	} else {
		box1.setFillColor(Color::White);
	}

	// If the mouse has entered box 2 then color it green
	if (box2.collide(Vector2f(Mouse::getPosition(window)))) {
		box2.setFillColor(Color::Green);
	}
	else {
		box2.setFillColor(Color::White);
	}

	// If box 1 and 2 have collided then turn 1 blue and 2 red
	if (box2.collide(box1.getCollider())) {
		box1.setFillColor(Color::Blue);
		box2.setFillColor(Color::Red);
	}
	*/
}

// Implements the render portion of our Game Loop Programming Pattern
void Game::render() {
	// This clears the window at the beginning of every frame
	window.clear();

	// Draw our boxes
	//box1.render(window, deltaTime);
	//box2.render(window, deltaTime);
	ball.render(window, deltaTime);
	paddle.render(window, deltaTime);

	/*
	for (int i = 0; i < 3; i++) {
		bricks[i].render(window, deltaTime);
	}*/
	level.render(window, deltaTime);

	ui.render(window, deltaTime);
	// Display the window buffer for this frame
	window.display();
}

// Implement destructor, make sure we free up any memory that we allocated here!
Game::~Game() {

}

void Game::initialize() {
	gameState = start;
	ball.reset(window);
	paddle = Paddle(1, BottomBorder, Vector2f(window.getSize().x / 2 - PADDLE_LENGTH / 2, window.getSize().y - PADDLE_BORDER_OFFSET - PADDLE_WIDTH), Vector2f(PADDLE_LENGTH, PADDLE_WIDTH));
	playerController = PlayerController(1, paddle, Controller::horizontal);

	//bricks[0] = Brick(Brick::normBrick, Vector2f(120, 60), Vector2f(BRICK_WIDTH, BRICK_HEIGHT));
	//bricks[1] = Brick(Brick::hardBrick, Vector2f(420, 60), Vector2f(BRICK_WIDTH, BRICK_HEIGHT));
	//bricks[2] = Brick(Brick::undestructible, Vector2f(270, 150), Vector2f(BRICK_WIDTH, BRICK_HEIGHT));
	levelCount = 1;
	level.loadLevel(LEVELS[0]);
	life = 2;
	score = 0;

	ui.updateLevel(levelCount);
	ui.updateHp(life);
	ui.updateScore(score);

}

void Game::nextLevel() {
	soundManager.playSFX(SoundManager::PassLevel);
	level.loadLevel(LEVELS[levelCount % 3]);
	levelCount++;
	ui.updateLevel(levelCount);
	gameState = start;
}

void Game::endGame() {
	soundManager.playSFX(SoundManager::GameOver);
	gameState = endgame;
	ball.setVelocity(Vector2f(0, 0));
	ball.setPosition(Vector2f(GameWidth + 100, GameHeight + 100));
	ui.endgame();
}
