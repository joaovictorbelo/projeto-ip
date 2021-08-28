/*******************************************************************************************
*
*   raylib [core] example - Keyboard input
*
*   This example has been created using raylib 1.0 (www.raylib.com)
*   raylib is licensed under an unmodified zlib/libpng license (View raylib.h for details)
*
*   Copyright (c) 2014 Ramon Santamaria (@raysan5)
*
********************************************************************************************/

#include "raylib.h"
#include <stdlib.h>

int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 450;
    
    // const int sceneSpeed = 1;
    const int gravity = 1;
    int Yvelocity = 0;

    InitWindow(screenWidth, screenHeight, "raylib [core] example - keyboard input");

    Vector2 playerSize = { 30, 40 };
    Vector2 playerPosition = { 0, screenHeight - playerSize.y};

    Rectangle playerHitbox = {playerPosition.x, playerPosition.y, playerSize.x, playerSize.y};

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update X position
        //----------------------------------------------------------------------------------
        if (playerPosition.x > 0) {
            // playerPosition.x -= sceneSpeed;

            if (IsKeyDown(KEY_LEFT)) {
               playerPosition.x -= 3; 
            }
        }

        if ((playerPosition.x < (screenWidth - playerSize.x)) && IsKeyDown(KEY_RIGHT)) {
            playerPosition.x += 3;
        }
        //----------------------------------------------------------------------------------

        // Update Y position
        //----------------------------------------------------------------------------------
        if ((playerPosition.y == screenHeight - playerSize.y)) {
            if (IsKeyPressed(KEY_UP)) {
                Yvelocity = 15;
            } else {
                Yvelocity = 0;
            }
        }

        playerPosition.y -= Yvelocity;
        Yvelocity -= gravity;
        //----------------------------------------------------------------------------------

        playerHitbox.x = playerPosition.x;
        playerHitbox.y = playerPosition.y;

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(RAYWHITE);

            DrawRectangleV(playerPosition, playerSize, GREEN);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}