//Funcoes referentes ao personagem do jogo (inicializacao, carregamento das texturas, renderizacao, movimentacao etc)

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

    player.playerSize = (Vector2){30, 125};
    // player.playerSize = (Vector2){30, 85};

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

void renderPlayerWalking(Player player, int *frameCounter, Texture2D cabo1, Texture2D cabo2, Texture2D cabo3, int boost) {
    float scale;
    if (boost) {
        scale = 2.0;
    } else {
        scale = 1.0;
    }

    if ((*frameCounter) >= 0 && (*frameCounter) <= 15) {
        DrawTextureEx(cabo2, (Vector2)player.playerPosition,0.0f, scale, WHITE);
    } else if ((*frameCounter) > 15 && (*frameCounter) <= 30) {
        DrawTextureEx(cabo1, (Vector2)player.playerPosition,0.0f, scale, WHITE);
    } else if ((*frameCounter) > 30 && (*frameCounter) <= 45) {
        DrawTextureEx(cabo3, (Vector2)player.playerPosition,0.0f, scale, WHITE);
    } else if ((*frameCounter) > 45 && (*frameCounter) <= 60) {
        DrawTextureEx(cabo1, (Vector2)player.playerPosition,0.0f, scale, WHITE);
    }
    
    if ((*frameCounter) == 60) {
        (*frameCounter) = 0;
    }

    (*frameCounter)++;
}

void renderPlayerStanding(Player player, Texture2D cabo1, int boost) {
    float scale;
    if (boost) {
        scale = 2.0;
    } else {
        scale = 1.0;
    }
    
    DrawTextureEx(cabo1, (Vector2)player.playerPosition,0.0f, scale, WHITE);
}

void updatePlayer(Player *player, int screenWidth, int screenHeight, float gravity, 
                    int *frameCounter, Texture2D cabo1, Texture2D cabo2, Texture2D cabo3, int boost) {

    int playerSpeed;

    if (IsKeyDown(KEY_SPACE)){
        playerSpeed = 5;
    } else {
        playerSpeed = 3;
    }

    if ((*player).playerPosition.x > 0) {
            if (IsKeyDown(KEY_LEFT)) {
               (*player).playerPosition.x -= playerSpeed; 
            }
        }

        if (((*player).playerPosition.x < (screenWidth - (*player).playerSize.x)) && IsKeyDown(KEY_RIGHT)) {
            (*player).playerPosition.x += playerSpeed;
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
        
        if((*player).playerPosition.y > screenHeight - 125) { 
            (*player).playerPosition.y = screenHeight - (*player).playerSize.y;
        }
        //----------------------------------------------------------------------------------

        (*player).playerHitbox.x = (*player).playerPosition.x;
        (*player).playerHitbox.y = (*player).playerPosition.y;

        if (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_LEFT)) {
            renderPlayerWalking(*player, frameCounter, cabo1, cabo2, cabo3, boost);
        } else {
            renderPlayerStanding(*player, cabo1, boost);
        }
}

int boostTimer(int *frames, int *boost) {
    float barSize = GetScreenWidth()/3;
    (*frames)++;
    DrawRectangle(barSize, 10, barSize, 20, WHITE);
    DrawRectangle(barSize, 10, barSize - barSize*((float)(*frames)/600), 20, RED);
    if ((*frames) == 600) {
        (*boost) = 0;
        (*frames) = 0;
        return 1;
    }
    return 0;
}

int checkBoost(Player *player, Rectangle boostRec, int *boost, int *frameCounter, int *points){
    int isImortal = 0;
    if(CheckCollisionRecs((*player).playerHitbox, boostRec)){
        (*boost) = 1;
        (*player).playerSize = (Vector2){60, 200};
        // (*player).playerPosition.y -= 85;
    }
    
    if (*boost) {
        if(boostTimer(frameCounter, boost)) {
            (*player).playerSize = (Vector2){30, 125};
            // (*player).playerPosition.y = 500;
        };
        isImortal = 1;
    }
    return isImortal;
}

