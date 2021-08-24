#include "raylib.h"
#include <time.h>
#include <stdlib.h>


void handleScreen() {
    /* 
        2.7 -> Escala utilizada para reduzir a largura.
        2.9 -> Escala utilizada para reduzir a altura.
    */
    const int screenWidth = 1280;
    const int screenHeight = 720;

    Vector2 mousePos = {0.0f, 0.0f};
    // faz um circulo que tem como centro a posicao do mouse


    InitWindow(screenWidth, screenHeight, "Destroievski");
    SetTargetFPS(60);

    Image backgroundImage = LoadImage("./src/asserts/menu/fundo.png");
    Image titleImage = LoadImage("./src/asserts/menu/nome.png");
    Image playButtonImage = LoadImage("./src/asserts/menu/jogar.png"); 
    Image storyButtonImage = LoadImage("./src/asserts/menu/historia.png");
    Image exitButtonImage = LoadImage("./src/asserts/menu/sair.png");
    Image playButtonImageHover = LoadImage("./src/asserts/menu/jogar-hover.png"); 
    Image storyButtonImageHover = LoadImage("./src/asserts/menu/historia-hover.png");
    Image exitButtonImageHover = LoadImage("./src/asserts/menu/sair-hover.png");
    
    
    ImageResize(&backgroundImage, screenWidth, screenHeight);
    ImageResize(&titleImage, titleImage.width/2.7, titleImage.height/2.9);
    ImageResize(&playButtonImage, playButtonImage.width/2.7, playButtonImage.height/2.9);
    ImageResize(&storyButtonImage, storyButtonImage.width/2.7, storyButtonImage.height/2.9);
    ImageResize(&exitButtonImage, exitButtonImage.width/2.7, exitButtonImage.height/2.9);
    ImageResize(&playButtonImageHover, playButtonImageHover.width/2.7, playButtonImageHover.height/2.9);
    ImageResize(&storyButtonImageHover, storyButtonImageHover.width/2.7, storyButtonImageHover.height/2.9);
    ImageResize(&exitButtonImageHover, exitButtonImageHover.width/2.7, exitButtonImageHover.height/2.9);

    Texture2D background = LoadTextureFromImage(backgroundImage);
    Texture2D title = LoadTextureFromImage(titleImage);
    Texture2D playButton = LoadTextureFromImage(playButtonImage);
    Texture2D storyButton = LoadTextureFromImage(storyButtonImage);
    Texture2D exitButton = LoadTextureFromImage(exitButtonImage);
    Texture2D playButtonHover = LoadTextureFromImage(playButtonImageHover);
    Texture2D storyButtonHover = LoadTextureFromImage(storyButtonImageHover);
    Texture2D exitButtonHover = LoadTextureFromImage(exitButtonImageHover);
 

    UnloadImage(backgroundImage);
    UnloadImage(titleImage);
    UnloadImage(playButtonImage);
    UnloadImage(storyButtonImage);
    UnloadImage(exitButtonImage);
    UnloadImage(playButtonImageHover);
    UnloadImage(storyButtonImageHover);
    UnloadImage(exitButtonImageHover);

    Rectangle playButtonBounds = { screenWidth/2.0 - playButtonImage.width/2.0, 275, playButtonImage.width, playButtonImage.height };
    Rectangle storyButtonBounds = { screenWidth/2.0 - storyButtonImage.width/2.0, 375, storyButtonImage.width, storyButtonImage.height };
    Rectangle exitButtonBounds = { screenWidth/2.0 - exitButtonImage.width/2.0, 475, exitButtonImage.width, exitButtonImage.height };
    
    while (!WindowShouldClose()) { 
        ClearBackground(RAYWHITE);
        mousePos = GetMousePosition();
        BeginDrawing();

        
        DrawTexture(background, 0.0, 0.0, WHITE);
        DrawTexture(title, 0.0, 0.0, WHITE);
        // DrawCircleV(GetMousePosition(), 10, ORANGE);
        DrawTexture(playButton, (screenWidth / 2.0 - playButtonImage.width / 2.0), 275, WHITE);
        DrawTexture(storyButton, (screenWidth / 2.0 - storyButtonImage.width / 2.0), 375, WHITE);
        DrawTexture(exitButton, (screenWidth / 2.0 - exitButtonImage.width / 2.0), 475, WHITE);

        if (CheckCollisionPointRec(mousePos, playButtonBounds))
        {
            DrawTexture(playButtonHover, (screenWidth / 2.0 - playButtonImage.width / 2.0), 275, WHITE);
        }
        if (CheckCollisionPointRec(mousePos, storyButtonBounds))
        {
            DrawTexture(storyButtonHover, (screenWidth / 2.0 - storyButtonImage.width / 2.0), 375, WHITE);
        }
        if (CheckCollisionPointRec(mousePos, exitButtonBounds))
        {
            DrawTexture(exitButtonHover, (screenWidth / 2.0 - exitButtonImage.width / 2.0), 475, WHITE);
        }

        EndDrawing();
    }

    void UnloadTexture(background);
}

int main() {
    handleScreen();

}
