#include "SoundManager.h"
#include <iostream>

using namespace gm;
using namespace sf;

SoundManager::SoundManager() {
    if (!sfxBuffer[BounceWall].loadFromFile("SFX/BounceAtWall.wav")) {
        std::cout << "Error loading sfx!" << std::endl;
    }
    if (!sfxBuffer[BouncePaddle].loadFromFile("SFX/BounceAtPaddle.wav")) {
        std::cout << "Error loading sfx!" << std::endl;
    }
    if (!sfxBuffer[HitBrick].loadFromFile("SFX/HitBrick.wav")) {
        std::cout << "Error loading sfx!" << std::endl;
    }
    if (!sfxBuffer[BreakBrick].loadFromFile("SFX/BreakBrick.wav")) {
        std::cout << "Error loading sfx!" << std::endl;
    }
    if (!sfxBuffer[UnbreakableBrick].loadFromFile("SFX/BounceAtWall.wav")) {
        std::cout << "Error loading sfx!" << std::endl;
    }
    if (!sfxBuffer[PassLevel].loadFromFile("SFX/PassLevel.wav")) {
        std::cout << "Error loading sfx!" << std::endl;
    }
    if (!sfxBuffer[LoseHp].loadFromFile("SFX/LoseHP.wav")) {
        std::cout << "Error loading sfx!" << std::endl;
    }
    if (!sfxBuffer[GameOver].loadFromFile("SFX/GameOver.wav")) {
        std::cout << "Error loading sfx!" << std::endl;
    }
    for (int i = 0; i < 8; i++) {
        sfx[i].setBuffer(sfxBuffer[i]);
    }

}

SoundManager::~SoundManager() {

}

void SoundManager::playSFX(soundType sound) {
    sfx[sound].play();
}