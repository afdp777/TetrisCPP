#pragma once
#include "grid.h"
#include "blocks.cpp"

#define SPEED_LIMIT (50)

class Game
{
    public:
        Game();
        ~Game();
        void draw();
        void handle_input();
        void move_block_down();
        bool game_over;
        int game_speed;
        int score;
        Music music;

    private:
        Block get_random_block();
        std::vector<Block> get_all_blocks();
        void move_block_left();
        void move_block_right();
        bool is_block_outside();
        void rotate_block();
        void lock_block();
        bool block_fits();
        void reset();
        void update_score(int lines_cleared, int movedown_points);
        Grid grid;
        std::vector<Block> blocks;
        Block current_block;
        Block next_block;
        Sound rotate_sound;
        Sound clear_sound;
};