#include "Blocks_system.h"

Blocks_system::Blocks_system()
{
    color_map = {
            std::pair<char, sf::Color>('t', sf::Color(236,121,236)),
            std::pair<char, sf::Color>('i', sf::Color(121,236,236)),
            std::pair<char, sf::Color>('o', sf::Color(236,236,121)),
            std::pair<char, sf::Color>('z', sf::Color(236,121,121)),
            std::pair<char, sf::Color>('s', sf::Color(150,236,121)),
            std::pair<char, sf::Color>('l', sf::Color(236,179,121)),
            std::pair<char, sf::Color>('j', sf::Color(121,121,236)),
            std::pair<char, sf::Color>('q', sf::Color(255,255,255))
    };

    //create game_field
    game_field.setSize(sf::Vector2f(200,400));
    game_field.setFillColor(sf::Color(200,200,200));
    game_field.setOutlineThickness(2);
    game_field.setOutlineColor(sf::Color(120,120,120));
    //create next_spawn_field
    next_spawn_field.setSize(sf::Vector2f(120,80));
    next_spawn_field.setFillColor(sf::Color(200,200,200));
    next_spawn_field.setOutlineThickness(2);
    next_spawn_field.setOutlineColor(sf::Color(120,120,120));

    //clear game fielld
    for(int x=1;x<11;x++){
        for(int y=0;y<20;y++){
            blocks_net.id[x][y]=0;
            blocks_net.color[x][y]=' ';
        }
    }
    //mark borders
    for(int y=0;y<21;y++){
        blocks_net.id[0][y]=-1;
        blocks_net.id[11][y]=-1;
        blocks_net.color[0][y]='q';
        blocks_net.color[11][y]='q';
    }
    for(int x=1;x<12;x++){
        blocks_net.id[x][20]=-1;
        blocks_net.color[x][20]='q';
    }

    //clear next spawn table
    for(int x=0;x<5;x++){
        for(int y=0;y<2;y++){
            next_spawn_space.id[x][y]=0;
            next_spawn_space.color[x][y]=' ';
        }
    }

    //create block_pointer
    block_pointer.setSize(sf::Vector2f(20,20));
    block_pointer.setOutlineColor(sf::Color::Black);
    block_pointer.setOutlineThickness(-1);
}

void Blocks_system::flor_crush(int flor)
{
    for(int x=1;x<11;x++){
        blocks_net.id[x][flor]=0;
        blocks_net.color[x][flor]=' ';
    }
    for(int x=1;x<11;x++){
      for(int y=flor;y>0;y--){
            blocks_net.id[x][y]=blocks_net.id[x][y-1];
            blocks_net.color[x][y]=blocks_net.color[x][y-1];
        }
    }
}

void Blocks_system::show_next_spawn(sf::RenderWindow &window){
    for(int y=0; y<2; y++){
        for(int x=0; x<5; x++){

//          chose color
            if(next_spawn_space.color[x][y] != ' ') {
                block_pointer.setFillColor(color_map[next_spawn_space.color[x][y]]);
                block_pointer.setPosition(sf::Vector2f(
                        x * 20 + game_field.getPosition().x + 300, y * 20 + game_field.getPosition().y + 20));
                window.draw(block_pointer);
            }
        }
    }
}

