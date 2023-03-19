/**
 * @file main.cpp
 * @author Will Skaggs
 *
 * Star field using c++ and raylib inspired by The Coding Train Coding Challenge #1.
 */

#include <iostream>
#include <vector>
#include <raylib.h>
#include "Star.h"

int main()
{
    // Configurations for the window
    const int ScreenWidth = 1600, ScreenHeight = 900;
    const int FrameRate = 60;
    const size_t NumStars = 1200;

    // Create the window
    InitWindow(ScreenWidth, ScreenHeight, "Star field");
    SetTargetFPS(FrameRate);

    // Exit if window was not created/initialized successfully
    if (!IsWindowReady()) {
        std::cout << "[ERROR]: Failed to initialized window" << std::endl;
        return 0;
    }

    // Game objects
    std::vector<Star> stars{NumStars};
    double lastTime = 0;

    // Main game loop
    while (!WindowShouldClose()) {
        // Update game objects
        double currTime = GetTime();
        double elapsed = currTime - lastTime;
        lastTime = currTime;

        for (Star & star : stars) {
            star.Update(elapsed);
        }

        // Redraw everything to the screen
        BeginDrawing();
            ClearBackground(BLACK);

            for (Star const & star : stars) {
                star.Draw();
            }
        EndDrawing();
    }

    // De-initialize
    CloseWindow();

    return 0;
}
