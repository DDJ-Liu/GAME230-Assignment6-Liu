#ifndef UI_H
#define UI_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Main.hpp>

namespace gm {
	class UI
	{
	private:
		sf::Font font;
		sf::Text mainText;
		sf::Text hp;
		sf::Text score;
	public:
		UI();
		~UI();
		void render(sf::RenderWindow& window, float deltaTime);
		void updateLevel(int level);
		void endgame();
		void updateScore(int score);
		void updateHp(int hp);
	};
}
#endif