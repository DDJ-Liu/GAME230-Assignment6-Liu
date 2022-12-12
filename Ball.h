#ifndef BALL_H
#define BALL_H
#include "GameObject.h"
#include "Paddle.h"
#include "Brick.h"
#include <iostream>

namespace gm {
    const float originalSize = 7;
    const float originalSpeedPerSecond = 200;
    const float protectTime = 0.05;

    class Ball :
        public GameObject
    {
    protected:
        sf::CircleShape body;
        sf::Vector2f velocity;
        float protectTimer = 0;

    public:
        Ball(const sf::Vector2f position, const float size = originalSize, const float speed = originalSpeedPerSecond);
        void update(sf::RenderWindow& window, float deltatime) override;
        void render(sf::RenderWindow& window, float deltatime) override;
        void setPosition(const sf::Vector2f& position) override;
        void move(const sf::Vector2f& velocity) override;
        sf::Vector2f getVelocity() const;
        void setVelocity(const sf::Vector2f& velocity);
        void bounceAtWall(Border border);
        void bounceAtPeddal(const Paddle& paddle);
        const sf::Color& getFillColor() const;
        void setFillColor(const sf::Color& color);
        void reset(sf::RenderWindow& window);
        Border hitBorder(const sf::RenderWindow& window);
        void stickTo(Paddle& paddle);
        Border hitBrick(Brick& brick);
        bool bounceAtBrick(Border border);
        ~Ball();
    };


}

#endif