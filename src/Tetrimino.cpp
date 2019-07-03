#include "Tetrimino.h"
/*
Tetrimino::Tetrimino()
{
    //ctor
}

Tetrimino::~Tetrimino()
{
    //dtor
}
*/
bool Tetrimino::is_move_possible(Blocks_net &net)
{
    sf::Vector2i main_b = try_position.main_block_pos;
    sf::Vector2i first_b = try_position.first_block_pos;
    sf::Vector2i second_b = try_position.second_block_pos;
    sf::Vector2i third_b = try_position.third_block_pos;

    //collision
    if((net.id[main_b.x][main_b.y]!=0 && net.id[main_b.x][main_b.y]!=block_id) ||
    (net.id[first_b.x][first_b.y]!=0 && net.id[first_b.x][first_b.y]!=block_id) ||
    (net.id[second_b.x][second_b.y]!=0 && net.id[second_b.x][second_b.y]!=block_id) ||
    (net.id[third_b.x][third_b.y]!=0 && net.id[third_b.x][third_b.y]!=block_id )){
        return 0;
    }
    return 1;
}

void Tetrimino::change_position(Blocks_net &net)
{
    current_position.main_block_pos=try_position.main_block_pos;
    current_position.spin=try_position.spin;

    current_position.first_block_pos=try_position.first_block_pos;
    current_position.second_block_pos=try_position.second_block_pos;
    current_position.third_block_pos=try_position.third_block_pos;
}

void Tetrimino::clear_pos(Blocks_net &net)
{
    //clear id
    net.id[current_position.main_block_pos.x][current_position.main_block_pos.y]=0;
    net.id[current_position.first_block_pos.x][current_position.first_block_pos.y]=0;
    net.id[current_position.second_block_pos.x][current_position.second_block_pos.y]=0;
    net.id[current_position.third_block_pos.x][current_position.third_block_pos.y]=0;

    //clear color
    net.color[current_position.main_block_pos.x][current_position.main_block_pos.y]=' ';
    net.color[current_position.first_block_pos.x][current_position.first_block_pos.y]=' ';
    net.color[current_position.second_block_pos.x][current_position.second_block_pos.y]=' ';
    net.color[current_position.third_block_pos.x][current_position.third_block_pos.y]=' ';
}

void Tetrimino::view_pos(Blocks_net &net)
{
    //view id
    net.id[current_position.main_block_pos.x][current_position.main_block_pos.y]=block_id;
    net.id[current_position.first_block_pos.x][current_position.first_block_pos.y]=block_id;
    net.id[current_position.second_block_pos.x][current_position.second_block_pos.y]=block_id;
    net.id[current_position.third_block_pos.x][current_position.third_block_pos.y]=block_id;

    //view color
    net.color[current_position.main_block_pos.x][current_position.main_block_pos.y]=block_color;
    net.color[current_position.first_block_pos.x][current_position.first_block_pos.y]=block_color;
    net.color[current_position.second_block_pos.x][current_position.second_block_pos.y]=block_color;
    net.color[current_position.third_block_pos.x][current_position.third_block_pos.y]=block_color;
}

void Tetrimino::prepare_next_spawn(Blocks_net &space)
{
    try_position.main_block_pos=sf::Vector2i(2,0);
    try_position.spin=0;

    //spin = 0
    rotation(space,"none");

    //set current position
    change_position(space);

    //clear color
    for(int y=0; y<2; y++){
        for(int x=0; x<5; x++){
            space.color[x][y]=' ';
        }
    }
    //set color
    space.color[current_position.main_block_pos.x][current_position.main_block_pos.y]=block_color;
    space.color[current_position.first_block_pos.x][current_position.first_block_pos.y]=block_color;
    space.color[current_position.second_block_pos.x][current_position.second_block_pos.y]=block_color;
    space.color[current_position.third_block_pos.x][current_position.third_block_pos.y]=block_color;
}

bool Tetrimino::create(Blocks_net &net,int &num_of_tetrimino)
{
    block_id = num_of_tetrimino;
    num_of_tetrimino++;


    //set try position
    try_position.main_block_pos=sf::Vector2i(5,0);
    try_position.spin=0;
    //spin = 0
    rotation(net,"none");

    //set current position
    change_position(net);

    view_pos(net);
}

void Tetrimino::fall(Blocks_net &net)
{
    clear_pos(net);

    try_position.main_block_pos.y++;
    rotation(net,"none");
    change_position(net);
    view_pos(net);
}
