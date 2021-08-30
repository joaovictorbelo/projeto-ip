#include "raylib.h"
#include <stdlib.h>

typedef struct Player{
    Vector2 playerPosition;
    Vector2 playerSize;
    Rectangle playerHitbox;
    float Yvelocity;
} Player;

Player initPlayer(int screenWidth, int screenHeight){
    Player player;

    player.playerSize = (Vector2){30, 85};
    player.playerPosition = (Vector2){0, screenHeight - player.playerSize.y};

    player.Yvelocity = 0;

    player.playerHitbox = (Rectangle){
        player.playerPosition.x,
        player.playerPosition.y,
        player.playerSize.x,
        player.playerSize.y
    };

    return player;
}

void renderPlayerWalking(Player player, int *frameCounter) {
    Texture2D cabo1 = LoadTexture("./src/asserts/jogador/cabo1.png");
    Texture2D cabo2 = LoadTexture("./src/asserts/jogador/cabo2.png");
    Texture2D cabo3 = LoadTexture("./src/asserts/jogador/cabo3.png");

    if ((*frameCounter) >= 0 && (*frameCounter) <= 15) {
        DrawTextureEx(cabo2, (Vector2)player.playerPosition,0.0f, 1.0f, WHITE);
    } else if ((*frameCounter) > 15 && (*frameCounter) <= 30) {
        DrawTextureEx(cabo1, (Vector2)player.playerPosition,0.0f, 1.0f, WHITE);
    } else if ((*frameCounter) > 30 && (*frameCounter) <= 45) {
        DrawTextureEx(cabo3, (Vector2)player.playerPosition,0.0f, 1.0f, WHITE);
    } else if ((*frameCounter) > 45 && (*frameCounter) <= 60) {
        DrawTextureEx(cabo1, (Vector2)player.playerPosition,0.0f, 1.0f, WHITE);
    }
    
    if ((*frameCounter) == 60) {
        (*frameCounter) = 0;
    }

    (*frameCounter)++;
}

void renderPlayerStanding(Player player) {
    Texture2D cabo1 = LoadTexture("./src/asserts/jogador/cabo1.png");
    
    DrawTextureEx(cabo1, (Vector2)player.playerPosition,0.0f, 1.0f, WHITE);
}

void updatePlayer(Player *player, int screenWidth, int screenHeight, float gravity, int *frameCounter){

    if ((*player).playerPosition.x > 0) {

            if (IsKeyDown(KEY_LEFT)) {
               (*player).playerPosition.x -= 3; 
            }
        }

        if (((*player).playerPosition.x < (screenWidth - (*player).playerSize.x)) && IsKeyDown(KEY_RIGHT)) {
            (*player).playerPosition.x += 3;
        }
        //----------------------------------------------------------------------------------

        // Update Y position
        //----------------------------------------------------------------------------------
        if (((*player).playerPosition.y == screenHeight - (*player).playerSize.y)) {
            if (IsKeyPressed(KEY_UP)) {
                (*player).Yvelocity = 15.0;
            } else {
                (*player).Yvelocity = 0;
            }
        }

        (*player).playerPosition.y -= (*player).Yvelocity;
        (*player).Yvelocity -= gravity;
        //----------------------------------------------------------------------------------

        (*player).playerHitbox.x = (*player).playerPosition.x;
        (*player).playerHitbox.y = (*player).playerPosition.y;

        if (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_LEFT)) {
            renderPlayerWalking(*player, frameCounter);
        } else {
            renderPlayerStanding(*player);
        }
}
