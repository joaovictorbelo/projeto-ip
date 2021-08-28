#include "raylib.h"
#include <stdlib.h>

typedef struct {
    Vector2 playerPosition;
    Vector2 playerSize;
    Rectangle playerHitbox;
} Player;

Player jogador(int screenWidth, int screenHeight)
{
    // const int sceneSpeed = 1;
    const int gravity = 1;
    int Yvelocity = 0;

    Player player1;

    player1.playerSize = (Vector2){30, 40};
    player1.playerPosition = (Vector2){0, screenHeight - player1.playerSize.y};

    player1.playerHitbox = (Rectangle){
        player1.playerPosition.x,
        player1.playerPosition.y,
        player1.playerSize.x,
        player1.playerSize.y
    };

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update X position
        //----------------------------------------------------------------------------------
        if (player1.playerPosition.x > 0) {
            // playerPosition.x -= sceneSpeed;

            if (IsKeyDown(KEY_LEFT)) {
               player1.playerPosition.x -= 3; 
            }
        }

        if ((player1.playerPosition.x < (screenWidth - player1.playerSize.x)) && IsKeyDown(KEY_RIGHT)) {
            player1.playerPosition.x += 3;
        }
        //----------------------------------------------------------------------------------

        // Update Y position
        //----------------------------------------------------------------------------------
        if ((player1.playerPosition.y == screenHeight - player1.playerSize.y)) {
            if (IsKeyPressed(KEY_UP)) {
                Yvelocity = 15;
            } else {
                Yvelocity = 0;
            }
        }

        player1.playerPosition.y -= Yvelocity;
        Yvelocity -= gravity;
        //----------------------------------------------------------------------------------

        player1.playerHitbox.x = player1.playerPosition.x;
        player1.playerHitbox.y = player1.playerPosition.y;
    }

    return player1;
}