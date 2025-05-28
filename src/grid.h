#pragma once
#include <vector>
#include <raylib.h>

class Grid
{
    public:
        Grid();
        void initialize();
        void print();
        void draw();
        bool is_cell_outside(int row, int column);
        bool is_cell_empty(int row, int column);
        int clear_full_rows();
        int grid[20][10];

    private:
        bool is_row_full(int row);
        void clear_row(int row);
        void move_row_down(int row, int num_rows);
        int num_rows;
        int num_cols;
        int cell_size;
        std::vector<Color> colors;
};