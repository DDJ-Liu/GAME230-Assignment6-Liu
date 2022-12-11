// Our include guards
// These are critical for preventing collision related errors from a file accidentally getting fully included multiple times
#ifndef GAME_H
#define GAME_H

/* SFML Includes             *
 * Add to every SFML project */
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Main.hpp>

 /* Our Includes */
#include "PlayerController.h"
#include "Ball.h"
#include "Brick.h"

// Place our classes, functions, variables, and so forth in their own namespace to avoid naming collisions
namespace gm {

	/* Our Game Class                               *
	 * Implements the Game Loop Programming Pattern */
	class Game {
	private:
		// The game window
		sf::RenderWindow window;
		// For tracking/maintaining delta time
		sf::Clock clock;
		float deltaTime;
		// Our game objects
		//Box box1;
		//Box box2;
		Ball ball;
		Paddle paddle;
		PlayerController playerController;
		Brick bricks[3];

		enum GameState { running, start, pause };
		GameState gameState = start;

	public:
		/* Protoypes */
		// Constructor
		Game();
		// Will start and manage the game loop programming pattern
		void run();
		// Game Loop Programming Pattern Methods
		void handleInput();
		void update();
		void render();
		// Destructor
		~Game();
		void initialize();
		
	};
}

#endif