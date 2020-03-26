#ifndef GAME_H
#define GAME_H
#include <SFML/Graphics.hpp>
#include "Blocks_system.h"

class Game
{
    public:
        sf::RenderWindow window;
        sf::Clock stoper;
        int flop_time = 400;
        sf::Event event;
        Blocks_system scene;
        char next_spawn = 0;
        int points = 0;
        sf::Font font;
        sf::Text points_monitor;

        Game();
        virtual ~Game() = default;
        int control();
        bool collision();
        void is_flor_full();
        void spawn_new_tetrimino();
        bool show();
        int play();
        bool is_game_over();
};

#endif // GAME_H
