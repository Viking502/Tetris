#ifndef TETRIMINO_H
#define TETRIMINO_H
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Structures.h"

class Tetrimino
{
    public:
        //Tetrimino();
        //virtual ~Tetrimino();

        int block_id;
        char block_color;
        Tetrimino_position current_position;
        Tetrimino_position try_position;

        bool is_move_possible(Blocks_net &blocks_net);
        void change_position(Blocks_net &blocks_net);
        void clear_pos(Blocks_net &blocks_net);
        void view_pos(Blocks_net &blocks_net);
        void prepare_next_spawn(Blocks_net &next_spawn_space);
        bool create(Blocks_net &blocks_net,int &numer_of_tetrimino);
        void fall(Blocks_net &blocks_net);

        virtual bool rotation(Blocks_net &blocks_net,std::string direction) = 0;

    protected:

    private:
};

#endif // TETRIMINO_H
