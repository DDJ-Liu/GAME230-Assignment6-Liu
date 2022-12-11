#ifndef BRICK_H
#define BRICK_H

#include "Box.h"

namespace gm {
    class Brick :
        public Box
    {
    protected:
        bool destructible = true;
        int hp = 0;

    public:
        enum BrickType { empty = 0, normBrick = 1, hardBrick = 2, undestructible = 3 };
        Brick(BrickType type, const sf::Vector2f& position, const sf::Vector2f& size);
        Brick();
        bool takeDamage();
        virtual void update(sf::RenderWindow& window, float deltaTime)override;
        virtual void render(sf::RenderWindow& window, float deltaTime)override;
        bool breakable()const;
        ~Brick();


    };
}
#endif
