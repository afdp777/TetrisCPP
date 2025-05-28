#include <iostream>
#include <raylib.h>
#include "game.h"
#include "colors.h"

using namespace std;
double last_update_time = 0;

bool event_triggered(double interval)
{
    double current_time = GetTime();
    if(current_time - last_update_time >= interval)
    {
        last_update_time = current_time;
        return true;
    }
    return false;
}

int main () 
{
    const int SCREEN_WIDTH = 500;
    const int SCREEN_HEIGHT = 620;

    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Tetris On C++ And Raylib");
    SetTargetFPS(60);

    Font font = LoadFontEx("resources/pixantiqua.ttf", 64, 0, 0);

    Game game = Game();

    while (WindowShouldClose() == false)
    {
        UpdateMusicStream(game.music);
        if(event_triggered((float)(game.game_speed / 1000.0f)))
        {
            game.move_block_down();
        }
        game.handle_input();
        BeginDrawing();
            ClearBackground(dark_blue);
            DrawTextEx(font, "Score", {365, 15}, 30, 2, WHITE);
            DrawRectangleRounded({320, 55, 170, 60}, 0.3, 6, light_blue);

            char score_text[10];
            sprintf(score_text, "%d", game.score);
            Vector2 text_size = MeasureTextEx(font, score_text, 38, 2);
            DrawTextEx(font, score_text, {320 + (88-text_size.x/2), 65}, 38, 2, WHITE);

            DrawTextEx(font, "Next", {370, 175}, 30, 2, WHITE);
            DrawRectangleRounded({320, 215, 170, 180}, 0.3, 6, light_blue);
            if(game.game_over)
            {
                DrawTextEx(font, "GAME OVER", {320, 450}, 30, 2, WHITE);
            }
            game.draw();
        EndDrawing();
    }

    CloseWindow();
}