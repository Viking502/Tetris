#include "Game.h"
#include "T_polyomino.h"
#include "I_polyomino.h"
#include "O_polyomino.h"
#include "Z_polyomino.h"
#include "S_polyomino.h"
#include "L_polyomino.h"
#include "J_polyomino.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdlib.h>
#include <time.h>

Game::Game(): next_spawn(rand() % 7)
{
    //ctor
    window.create(sf::VideoMode( 640, 480 ), "Tetris 1.0");
    scene.game_field.setPosition(window.getSize().x / 2 - scene.game_field.getSize().x, 40);
    scene.next_spawn_field.setPosition(window.getSize().x / 2 + 100, 40);

    if(!font.loadFromFile("fonts/digital-7.ttf")){
        std::cout<<"can't load font from file\n";
        //system("pwd");
    }else{
        points_monitor.setFont(font);
    }
    points_monitor.setCharacterSize(24);
    points_monitor.setFillColor(sf::Color::Yellow);
    points_monitor.setStyle(sf::Text::Bold);
    points_monitor.setPosition(10, 10);

    switch(next_spawn){
        case 0:
            scene.next_tetrimino = std::make_unique<T_polyomino>();
        break;
        case 1:
            scene.next_tetrimino = std::make_unique<I_polyomino>();
        break;
        case 2:
            scene.next_tetrimino = std::make_unique<O_polyomino>();
        break;
        case 3:
            scene.next_tetrimino = std::make_unique<Z_polyomino>();
        break;
        case 4:
            scene.next_tetrimino = std::make_unique<S_polyomino>();
        break;
        case 5:
            scene.next_tetrimino = std::make_unique<L_polyomino>();
        break;
        case 6:
            scene.next_tetrimino = std::make_unique<J_polyomino>();
        break;
        default:
            std::cout<<"spawn error\n";
        break;
    }
}

int Game::control()
{
    while( window.pollEvent( event ) ){
        if( event.type == sf::Event::Closed )
            window.close();
        if((event.type==sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Down)){
            if(stoper.getElapsedTime().asMilliseconds()>10){
                collision();
                scene.tetrimino->try_position.main_block_pos.y++;
                scene.tetrimino ->rotation(scene.blocks_net,"none");
                //set new position of tetrimino
                scene.tetrimino->clear_pos(scene.blocks_net);
                scene.tetrimino->change_position(scene.blocks_net);
                scene.tetrimino->view_pos(scene.blocks_net);
                collision();
                //window.clear();
                show();
               // window.display();
                stoper.restart();
            }
        }
        if((event.type==sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Right)){
            if(stoper.getElapsedTime().asMilliseconds()>10){
                scene.tetrimino->try_position.main_block_pos.x++;
                scene.tetrimino ->rotation(scene.blocks_net,"none");
                if(scene.tetrimino->is_move_possible(scene.blocks_net)){
                    //set new position of tetrimino
                    scene.tetrimino->clear_pos(scene.blocks_net);
                    scene.tetrimino->change_position(scene.blocks_net);
                    scene.tetrimino->view_pos(scene.blocks_net);
                    //collision();
                    show();
                }else{
                    scene.tetrimino->try_position.main_block_pos.x--;
                    scene.tetrimino ->rotation(scene.blocks_net,"none");
                    //scene.tetrimino->\view_pos(scene.blocks_net);
                }
            }
        }
        if((event.type==sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Left)){
            if(stoper.getElapsedTime().asMilliseconds()>10){
                scene.tetrimino->try_position.main_block_pos.x--;
                scene.tetrimino ->rotation(scene.blocks_net,"none");
                if(scene.tetrimino->is_move_possible(scene.blocks_net)){
                    //set new position of tetrimino
                    scene.tetrimino->clear_pos(scene.blocks_net);
                    scene.tetrimino->change_position(scene.blocks_net);
                    scene.tetrimino->view_pos(scene.blocks_net);
                    //collision();
                    show();
                }else{
                    scene.tetrimino->try_position.main_block_pos.x++;
                    scene.tetrimino ->rotation(scene.blocks_net,"none");
                    //scene.tetrimino->view_pos(scene.blocks_net);
                }
            }
        }
        if((event.type==sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Z)){
            if(stoper.getElapsedTime().asMilliseconds()>10){
                scene.tetrimino ->rotation(scene.blocks_net,"left");

                if(scene.tetrimino->is_move_possible(scene.blocks_net)){
                    //set new position of tetrimino
                    scene.tetrimino->clear_pos(scene.blocks_net);
                    scene.tetrimino->change_position(scene.blocks_net);
                    scene.tetrimino->view_pos(scene.blocks_net);
                    //collision();
                    show();
                }else{
                    scene.tetrimino ->rotation(scene.blocks_net,"right");
                }
            }
        }
        if((event.type==sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::X)){
            if(stoper.getElapsedTime().asMilliseconds()>10){
                scene.tetrimino ->rotation(scene.blocks_net,"right");

                if(scene.tetrimino->is_move_possible(scene.blocks_net)){
                    //set new position of tetrimino
                    scene.tetrimino->clear_pos(scene.blocks_net);
                    scene.tetrimino->change_position(scene.blocks_net);
                    scene.tetrimino->view_pos(scene.blocks_net);
                    //collision();
                    show();
                }else{
                    scene.tetrimino ->rotation(scene.blocks_net,"left");
                }
            }
        }
    }
}

bool Game::collision()
{
    scene.tetrimino->try_position.main_block_pos.y++;
    scene.tetrimino->rotation(scene.blocks_net,"none");
    if(scene.tetrimino->is_move_possible(scene.blocks_net)!=1){

        scene.tetrimino->try_position.main_block_pos.y--;
        scene.tetrimino->rotation(scene.blocks_net,"none");

        points++;

        if(flop_time>100)
            flop_time-=5;

        is_flor_full();
        is_game_over();

        spawn_new_tetrimino();

        show();

        stoper.restart();

        return true;
    }
    scene.tetrimino->try_position.main_block_pos.y--;
    scene.tetrimino->rotation(scene.blocks_net,"none");

    return false;
}

void Game::is_flor_full()
{
    bool flor_is_full;

    for(int y=1;y<20;y++){
        flor_is_full=1;
        for(int x=1;x<11;x++){
            if(scene.blocks_net.id[x][y]<1)
                flor_is_full=0;
        }
        if(flor_is_full==1){
            scene.flor_crush(y);
            points+=10;
        }
    }
}

void Game::spawn_new_tetrimino()
{
    scene.tetrimino = std::move(scene.next_tetrimino);

    next_spawn = rand()%7;
    switch(next_spawn){
        case 0:
            scene.next_tetrimino = std::make_unique<T_polyomino>();
            break;
        case 1:
            scene.next_tetrimino = std::make_unique<I_polyomino>();
            break;
        case 2:
            scene.next_tetrimino = std::make_unique<O_polyomino>();
            break;
        case 3:
            scene.next_tetrimino = std::make_unique<Z_polyomino>();
            break;
        case 4:
            scene.next_tetrimino = std::make_unique<S_polyomino>();
            break;
        case 5:
            scene.next_tetrimino = std::make_unique<L_polyomino>();
            break;
        case 6:
            scene.next_tetrimino = std::make_unique<J_polyomino>();
            break;
        default:
            std::cout<<"spawn error\n";
        break;
    }
    scene.next_tetrimino->prepare_next_spawn(scene.next_spawn_space);

    scene.tetrimino -> create(scene.blocks_net, scene.number_of_tetrimino);
    scene.tetrimino -> view_pos(scene.blocks_net);
    show();
}

bool Game::show()
{
    window.clear();
    window.draw(scene.game_field);
    window.draw(scene.next_spawn_field);

    std::string p = std::to_string(points);
    points_monitor.setString(p);
    window.draw(points_monitor);


    for(int x=0;x<12;x++){
        for(int y=0;y<21;y++){
            if(scene.blocks_net.color[x][y] != ' ') {
                scene.block_pointer.setFillColor(scene.color_map[scene.blocks_net.color[x][y]]);
                scene.block_pointer.setPosition(sf::Vector2f((x - 1) * 20 + scene.game_field.getPosition().x,
                                                             y * 20 + scene.game_field.getPosition().y));
                window.draw(scene.block_pointer);
            }
        }
    }
    scene.show_next_spawn(window);
    window.display();
    return 1;
}

int Game::play()
{
    spawn_new_tetrimino();

    while(window.isOpen()){
        control();

        if(stoper.getElapsedTime().asMilliseconds()>flop_time){

            collision();
            scene.tetrimino -> fall(scene.blocks_net);
            collision();
            scene.tetrimino -> view_pos(scene.blocks_net);
            show();
            stoper.restart();
        }
    }
    return 0;
}

bool Game::is_game_over()
{

    for(int x=1;x<11;x++){
        if(scene.blocks_net.id[x][1]>0){

//            window.clear(sf::Color(60, 60, 60, 0));
            sf::RectangleShape temp{static_cast<sf::Vector2f>(window.getSize())};
            temp.setPosition(0, 0);
            temp.setFillColor(sf::Color{60, 60, 60, 160});
            window.draw(temp);
            sf::Text endText("GAME OVER", font, 80);
            endText.setFillColor(sf::Color::Red);
            endText.setPosition(window.getSize().x / 2 - 160,window.getSize().y / 2 - 200);
            window.draw(endText);

            endText.setString(std::to_string(points));
            endText.setCharacterSize(140);
            endText.setPosition(window.getSize().x / 2 - 40,window.getSize().y / 2 - 60);
            window.draw(endText);
            window.display();
            sf::sleep(sf::seconds(1));

            points=0;
            flop_time=400;
            //clear game fielld

            for(int dx=1;dx<11;dx++){
                for(int dy=0;dy<20;dy++){
                    scene.blocks_net.id[dx][dy]=0;
                    scene.blocks_net.color[dx][dy]=' ';
                }
            }
            return true;
        }
    }
    return false;
}
