#ifndef GAMEVARIABLESETTINGS_H
#define GAMEVARIABLESETTINGS_H

namespace gm {
	// Box movement speed
	const int PlayerMovementSpeedPerSecond = 350;

    const int GameWidth = 600;
    const int GameHeight = 720;

    const int PADDLE_LENGTH = 100;
    const int PADDLE_WIDTH = 20;
    const int PADDLE_BORDER_OFFSET = 40;
    const int BALL_SIZE = 300;

    const float VELOCITY_AMPLIFIER = 0.03;
    const float VELOCITY_FIXED_CHANGE_AMOUNT = 80;
    const float SCORED_PAUSE_TIME = 3;
    const float ETERNAL_PAUSE_TIME = 99999;

    const float MOUSE_CONTROL_TOLERANCE = 20;

    const int BRICKS_COUNT_X = 10;
    const int BRICKS_COUNT_Y = 20;
    const int BRICK_WIDTH = 60;
    const int BRICK_HEIGHT = 20;

    const sf::Color  BRICK_FILL_COLOR[4] = { sf::Color::Transparent,sf::Color::Cyan,sf::Color::Magenta,sf::Color::Color(100,100,100) };
    const sf::Color  BRICK_OUTLINE_COLOR[4] = { sf::Color::Transparent,sf::Color::White,sf::Color::White,sf::Color::Color(100,100,100) };

    enum Border {
        NoBorder = 0,
        LeftBorder = 1,
        RightBorder = 2,
        BottomBorder = 3,
        TopBorder = 4
    };
    enum MovementDirection {
        None = 0,
        Up = -1,
        Down = 1,
        Left = -2,
        Right = 2
    };

    const int levelNum = 3;
    const int LEVELS[levelNum][BRICKS_COUNT_Y][BRICKS_COUNT_X] =
    { {
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,1,0,0,0,0,0,1,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,3,3,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0}
        },{
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,2,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0}
        }, {
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,1,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0}
        } };

}


#endif // !1
