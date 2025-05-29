# Tetris in C++ and Raylib
Result of following the <a href="https://www.youtube.com/watch?v=wVYKG_ch4yM">Tetris C++ Game Tutorial</a> with minor changes such as:
* game play gets faster as the score increases,
* sounds are closer to original game,
* use of volume control to lower background music,
* background music stops playing at game over and restarts when game is restarted,
* changed the handling of reading keyboard when game over is detected,
* disabled the Raylib debug console when building the executable by adding "CFLAGS += -Wl,--subsystem,windows" in line 211 of Makefile.

# Development Environment Setup
1. Install Raylib using the installer from <a href="https://raylib.com">Raylib website</a>.
2. Clone this repo and open using VS Code.
3. Press F5 on the keyboard to compile and run the program.

# Game Control
Use the arrow keys:
* Left and right arrow keys to position the block horizontally,
* Down arrow key to hasten the block's falling speed,
* Up arrow key to rotate the block.

This project uses the <a href="https://github.com/educ8s/Raylib-CPP-Starter-Template-for-VSCODE-V2">Raylib C++ Starter Template for Visual Studio Code on Windows</a>.
