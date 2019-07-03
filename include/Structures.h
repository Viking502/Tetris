
struct Blocks_net{
    int id[12][21];
    char color[12][21];
};

struct Tetrimino_position{
    sf::Vector2i main_block_pos;
    sf::Vector2i first_block_pos;
    sf::Vector2i second_block_pos;
    sf::Vector2i third_block_pos;
    int spin;
};

