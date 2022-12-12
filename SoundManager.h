#ifndef SOUNDMANAGER_H
#define SOUNDMANAGER_H
#include <SFML/Audio.hpp>
namespace gm {

	class SoundManager
	{
	private:
		sf::SoundBuffer sfxBuffer[8];
		sf::Sound sfx[8];
	public:
		SoundManager();
		~SoundManager();
		enum soundType {
			BounceWall = 0,
			BouncePaddle = 1,
			HitBrick = 2,
			BreakBrick = 3,
			UnbreakableBrick=4,
			PassLevel=5,
			LoseHp=6,
			GameOver=7
		};
		void playSFX(soundType sound);
	};
}
#endif // !SOUNDMANAGER_H