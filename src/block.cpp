#include "block.h"

Block::Block()
{
    cell_size = 30;
    rotation_state = 0;
    colors = get_cell_colors();
    row_offset = 0;
    col_offset = 0;
}

void Block::draw(int offset_x, int offset_y)
{
    std::vector<Position> tiles = get_cell_positions();
    for(Position item: tiles)
    {
        DrawRectangle(item.column * cell_size + offset_x, item.row * cell_size + offset_y, cell_size-1, cell_size-1, colors[id]);
    }
}

void Block::move(int rows, int columns)
{
    row_offset += rows;
    col_offset += columns;
}

std::vector<Position> Block::get_cell_positions()
{
    std::vector<Position> tiles = cells[rotation_state];
    std::vector<Position> moved_tiles;
    for(Position item: tiles)
    {
        Position new_pos = Position(item.row + row_offset, item.column + col_offset);
        moved_tiles.push_back(new_pos);
    }
    return moved_tiles;
}

void Block::rotate()
{
    rotation_state++;
    if(rotation_state >= (int)cells.size())
    {
        rotation_state = 0;
    }
}

void Block::undo_rotation()
{
    rotation_state--;
    if(rotation_state<0)
    {
        rotation_state = (int)cells.size() - 1;
    }
}
