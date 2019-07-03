#include "S_polyomino.h"
#include <SFML/Graphics.hpp>

S_polyomino::S_polyomino()
{
    block_color='s';
    //ctor
}

S_polyomino::~S_polyomino()
{
    //dtor
}

bool S_polyomino::rotation(Blocks_net &net,std::string direction)
{
    //clear old position of tetrimino
    //clear_pos(net);

    if(direction=="right"){
        if(try_position.spin<3){
           try_position.spin++;
        }else{
           try_position.spin=0;
        }
    }
    if(direction=="left"){
        if(try_position.spin>0){
           try_position.spin--;
        }else{
            try_position.spin=3;
        }
    }else if(direction!="none"){
        return 0;
    }

    //rotate
    switch(try_position.spin){
        case 0:
            try_position.first_block_pos=sf::Vector2i(try_position.main_block_pos.x-1,try_position.main_block_pos.y);
            try_position.second_block_pos=sf::Vector2i(try_position.main_block_pos.x,try_position.main_block_pos.y+1);
            try_position.third_block_pos=sf::Vector2i(try_position.main_block_pos.x+1,try_position.main_block_pos.y+1);
            break;
        case 1:
            try_position.first_block_pos=sf::Vector2i(try_position.main_block_pos.x,try_position.main_block_pos.y-1);
            try_position.second_block_pos=sf::Vector2i(try_position.main_block_pos.x-1,try_position.main_block_pos.y);
            try_position.third_block_pos=sf::Vector2i(try_position.main_block_pos.x-1,try_position.main_block_pos.y+1);
            break;
        case 2:
            try_position.first_block_pos=sf::Vector2i(try_position.main_block_pos.x+1,try_position.main_block_pos.y);
            try_position.second_block_pos=sf::Vector2i(try_position.main_block_pos.x,try_position.main_block_pos.y-1);
            try_position.third_block_pos=sf::Vector2i(try_position.main_block_pos.x-1,try_position.main_block_pos.y-1);
            break;
        case 3:
            try_position.first_block_pos=sf::Vector2i(try_position.main_block_pos.x,try_position.main_block_pos.y+1);
            try_position.second_block_pos=sf::Vector2i(try_position.main_block_pos.x+1,try_position.main_block_pos.y);
            try_position.third_block_pos=sf::Vector2i(try_position.main_block_pos.x+1,try_position.main_block_pos.y-1);
            break;
    }

    return 1;
}
