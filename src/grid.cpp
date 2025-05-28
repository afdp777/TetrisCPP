#include <iostream>
#include "grid.h"
#include "colors.h"

Grid::Grid()
{
    num_rows = 20;
    num_cols = 10;
    cell_size = 30;
    initialize();
    colors = get_cell_colors();
}

void Grid::initialize()
{
    for(int row = 0; row < num_rows; row++)
    {
        for(int column = 0; column < num_cols; column++)
        {
            grid[row][column] = 0;
        }
    }
}

void Grid::print()
{
    for(int row = 0; row < num_rows; row++)
    {
        for(int column = 0; column < num_cols; column++)
        {
            std::cout << grid[row][column] << " ";
        }
        std::cout << std::endl;
    }
}

void Grid::draw()
{
    for(int row = 0; row < num_rows; row++)
    {
        for(int column = 0; column < num_cols; column++)
        {
            int cell_value = grid[row][column];
            DrawRectangle(column * cell_size + 11, row * cell_size + 11, cell_size - 1, cell_size - 1, colors[cell_value]);
        }
    }
}

bool Grid::is_cell_outside(int row, int column)
{
    if(row>=0 && row < num_rows && column>=0 && column < num_cols)
    {
        return false;
    }
    return true;
}

bool Grid::is_cell_empty(int row, int column)
{
    if(grid[row][column] == 0)
    {
        return true;
    }
    return false;
}

int Grid::clear_full_rows()
{
    int completed = 0;
    for(int row = num_rows -1; row>=0; row--)
    {
        if(is_row_full(row))
        {
            clear_row(row);
            completed++;
        }
        else if(completed>0)
        {
            move_row_down(row, completed);
        }
    }
    return completed;
}

bool Grid::is_row_full(int row)
{
    for(int column = 0; column<num_cols; column++)
    {
        if(grid[row][column] == 0)
        {
            return false;
        }
    }
    return true;
}

void Grid::clear_row(int row)
{
    for(int column = 0; column<num_cols; column++)
    {
        grid[row][column] = 0;
    }
}

void Grid::move_row_down(int row, int num_rows)
{
    for(int column = 0; column<num_cols; column++)
    {
        grid[row + num_rows][column] = grid[row][column];
        grid[row][column] = 0;
    }
}
