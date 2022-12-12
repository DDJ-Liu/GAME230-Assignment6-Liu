#include "UI.h"
#include "GameVariableSettings.h"

using namespace gm;
using namespace sf;

UI::UI() {
	if (!font.loadFromFile("arial.ttf"))
	{
		// error...
	}

	mainText.setFont(font);
	mainText.setCharacterSize(60);
	mainText.setPosition(GameWidth / 2 - 120, GameHeight / 2 + 10);
	mainText.setFillColor(sf::Color(200, 200, 200, 150));
	mainText.setStyle(Text::Style::Bold);

	hp.setFont(font);
	hp.setCharacterSize(24);
	hp.setPosition(GameWidth / 2 - 150, GameHeight / 2 + 110);
	hp.setFillColor(sf::Color(200, 200, 200, 150));

	score.setFont(font);
	score.setCharacterSize(24);
	score.setPosition(GameWidth / 2 + 65, GameHeight / 2 + 110);
	score.setFillColor(sf::Color(200, 200, 200, 150));

}

UI::~UI() {

}

void UI::render(sf::RenderWindow& window, float deltaTime) {
	window.draw(mainText);
	window.draw(hp);
	window.draw(score);
}

void UI::updateLevel(int level) {
	mainText.setString("LEVEL " + std::to_string(level));
}

void UI::endgame() {
	mainText.setString("Game Over");
	mainText.setPosition(GameWidth / 2 - 160, GameHeight / 2 - 10);
}

void UI::updateScore(int score) {
	this->score.setString("score: " + std::to_string(score));
}

void UI::updateHp(int hp) {
	this->hp.setString("HP: " + std::to_string(hp));
}