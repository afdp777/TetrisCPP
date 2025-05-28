#pragma once
#include <vector>
#include <map>
#include "position.h"
#include "colors.h"

class Block
{
    public:
        Block();
        void draw(int offset_x, int offset_y);
        void move(int rows, int columns);
        std::vector<Position> get_cell_positions();
        void rotate();
        void undo_rotation();
        int id;
        std::map<int, std::vector<Position>> cells;

    private:
        int cell_size;
        int rotation_state;
        std::vector<Color> colors;
        int row_offset;
        int col_offset;
};