#ifndef PLAYERCONTROLLER_H
#define PLAYERCONTROLLER_H

#include "Controller.h"
#include <SFML/Window.hpp>

namespace gm {
    class PlayerController :
        public Controller
    {
    protected:
        //sf::Keyboard::Key key1;//Left or Up
        //sf::Keyboard::Key key2;//Right or Down
    public:
        PlayerController(int id, Paddle& p, PaddleDirection pd);
        PlayerController();
        ~PlayerController();
        virtual void update(sf::RenderWindow& window, float deltaTime)override;
        void handleInput(sf::RenderWindow& window, sf::Event event);
    };
}

#endif // !PLAYERCONTROLLER_H