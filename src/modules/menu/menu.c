#include "raylib.h"
#include <time.h>
#include <stdlib.h>
#include "../obstacules/obstacules.h"
#include "../historia/historia.h"
typedef enum gameScreen {MENU, JOGAR, HISTORIA, SAIR} gameScreen;

void menuScreen() {
    /* 
        2.7 -> Escala utilizada para reduzir a largura.
        2.9 -> Escala utilizada para reduzir a altura.
    */
    const int screenWidth = 1280;
    const int screenHeight = 720;
    
    int actualPosOfHistoryText = 0;

    int shouldContinueInTheAnotherScreen = 1;
    Vector2 mousePos = {0.0f, 0.0f};
    
    gameScreen currentScreen = MENU;
    Rectangle player = {30, 30, 80, 80};

    InitWindow(screenWidth, screenHeight, "Destroievski");
    SetTargetFPS(120);

    Image backgroundImage = LoadImage("./src/asserts/menu/fundo.png");
    Image titleImage = LoadImage("./src/asserts/menu/nome.png");
    Image playButtonImage = LoadImage("./src/asserts/menu/jogar.png"); 
    Image storyButtonImage = LoadImage("./src/asserts/menu/historia.png");
    Image exitButtonImage = LoadImage("./src/asserts/menu/sair.png");
    Image backButtonImage = LoadImage("./src/asserts/menu/voltar.png");
    Image playButtonImageHover = LoadImage("./src/asserts/menu/jogar-hover.png"); 
    Image storyButtonImageHover = LoadImage("./src/asserts/menu/historia-hover.png");
    Image exitButtonImageHover = LoadImage("./src/asserts/menu/sair-hover.png");
    Image backButtonImageHover = LoadImage("./src/asserts/menu/voltar-hover.png");
    Image* obstaculesImages = obstacules_image(3);
    Image returnButtonImage = LoadImage("./src/asserts/menu/return.png");
    Image returnButtonImageHover = LoadImage("./src/asserts/menu/return-hover.png");
    
    
    ImageResize(&backgroundImage, screenWidth, screenHeight);
    ImageResize(&titleImage, titleImage.width/2.7, titleImage.height/2.9);
    ImageResize(&playButtonImage, playButtonImage.width/2.7, playButtonImage.height/2.9);
    ImageResize(&storyButtonImage, storyButtonImage.width/2.7, storyButtonImage.height/2.9);
    ImageResize(&exitButtonImage, exitButtonImage.width/2.7, exitButtonImage.height/2.9);
    ImageResize(&backButtonImage, backButtonImage.width/2.7, backButtonImage.height/2.9);
    ImageResize(&playButtonImageHover, playButtonImageHover.width/2.7, playButtonImageHover.height/2.9);
    ImageResize(&storyButtonImageHover, storyButtonImageHover.width/2.7, storyButtonImageHover.height/2.9);
    ImageResize(&exitButtonImageHover, exitButtonImageHover.width/2.7, exitButtonImageHover.height/2.9);
    ImageResize(&backButtonImageHover, backButtonImageHover.width/2.7, backButtonImageHover.height/2.9);
    ImageResize(&returnButtonImage, returnButtonImage.width/7.7, returnButtonImage.height/7.9);
    ImageResize(&returnButtonImageHover, returnButtonImageHover.width/7.7, returnButtonImageHover.height/7.9);


    Texture2D background = LoadTextureFromImage(backgroundImage);
    Texture2D title = LoadTextureFromImage(titleImage);
    Texture2D playButton = LoadTextureFromImage(playButtonImage);
    Texture2D storyButton = LoadTextureFromImage(storyButtonImage);
    Texture2D exitButton = LoadTextureFromImage(exitButtonImage);
    Texture2D backButton = LoadTextureFromImage(backButtonImage);
    Texture2D playButtonHover = LoadTextureFromImage(playButtonImageHover);
    Texture2D storyButtonHover = LoadTextureFromImage(storyButtonImageHover);
    Texture2D exitButtonHover = LoadTextureFromImage(exitButtonImageHover);
    Texture2D backButtonHover = LoadTextureFromImage(backButtonImageHover);
    Texture2D* obstacules2d = malloc(sizeof(Image) * 1);
    Texture2D returnButton = LoadTextureFromImage(returnButtonImage);
    Texture2D returnButtonHover = LoadTextureFromImage(returnButtonImageHover);


    obstacules2d = obstacules_texture_2d(3, obstaculesImages);


    int die = 0;
    int init_game = 0;
    Obstacule* obstacles = obstacules_init(3);

    UnloadImage(backgroundImage);
    UnloadImage(titleImage);
    UnloadImage(playButtonImage);
    UnloadImage(storyButtonImage);
    UnloadImage(exitButtonImage);
    UnloadImage(backButtonImage);
    UnloadImage(playButtonImageHover);
    UnloadImage(storyButtonImageHover);
    UnloadImage(exitButtonImageHover);
    UnloadImage(backButtonImageHover);
    UnloadImage(returnButtonImage);
    UnloadImage(returnButtonImageHover);

    Rectangle playButtonBounds = { screenWidth/2.0 - playButtonImage.width/2.0, 275, playButtonImage.width, playButtonImage.height };
    Rectangle storyButtonBounds = { screenWidth/2.0 - storyButtonImage.width/2.0, 375, storyButtonImage.width, storyButtonImage.height };
    Rectangle exitButtonBounds = { screenWidth/2.0 - exitButtonImage.width/2.0, 475, exitButtonImage.width, exitButtonImage.height };
    Rectangle backButtonBounds = { 10, 600, backButtonImage.width, backButtonImage.height };
    

    Font font = LoadFont("./src/font/BarlowCondensed-SemiBold.ttf"); 

    while (!WindowShouldClose() && currentScreen != SAIR) { 
        ClearBackground(RAYWHITE);
        mousePos = GetMousePosition();
        BeginDrawing();

        switch (currentScreen) {
            case MENU:
                DrawTexture(background, 0.0, 0.0, WHITE);
                DrawTexture(title, 0.0, 0.0, WHITE);
                DrawTexture(playButton, (screenWidth / 2.0 - playButtonImage.width / 2.0), 275, WHITE);
                DrawTexture(storyButton, (screenWidth / 2.0 - storyButtonImage.width / 2.0), 375, WHITE);
                DrawTexture(exitButton, (screenWidth / 2.0 - exitButtonImage.width / 2.0), 475, WHITE);

                if (CheckCollisionPointRec(mousePos, playButtonBounds))
                {
                    DrawTexture(playButtonHover, (screenWidth / 2.0 - playButtonImage.width / 2.0), 275, WHITE);
                    if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) currentScreen = JOGAR;
                }
                if (CheckCollisionPointRec(mousePos, storyButtonBounds))
                {
                    DrawTexture(storyButtonHover, (screenWidth / 2.0 - storyButtonImage.width / 2.0), 375, WHITE);
                    if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) currentScreen = HISTORIA;
                }
                if (CheckCollisionPointRec(mousePos, exitButtonBounds))
                {
                    DrawTexture(exitButtonHover, (screenWidth / 2.0 - exitButtonImage.width / 2.0), 475, WHITE);
                    if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) currentScreen = SAIR;
                }
                break;
            case JOGAR:
                ClearBackground(RAYWHITE);
                update_obstacules(obstacles, 3, obstacules2d);
    
                    
                DrawTexture(backButton, 10, 600, WHITE);
                if(CheckCollisionPointRec(mousePos, backButtonBounds))
                {
                    DrawTexture(backButtonHover, 10, 600, WHITE);
                    if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) currentScreen = MENU;
                }

                              
                break;
            case HISTORIA:
                ClearBackground(RAYWHITE);

                actualPosOfHistoryText = historiaScreen(background, font, returnButton, returnButtonHover, 
                actualPosOfHistoryText);
                if(actualPosOfHistoryText == -1) {
                    currentScreen = MENU;
                }
                
                if(CheckCollisionPointRec(mousePos, backButtonBounds))
                {
                    DrawTexture(backButtonHover, 10, 600, WHITE);
                    if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) currentScreen = MENU;
                }
                break;
            case SAIR:
                DrawTexture(background, 0.0, 0.0, WHITE);
                break;
        }
        
        EndDrawing();
    }

    UnloadTexture(background);
    UnloadTexture(title);
    UnloadTexture(playButton);
    UnloadTexture(storyButton);
    UnloadTexture(exitButton);
    UnloadTexture(playButtonHover);
    UnloadTexture(storyButtonHover);
    UnloadTexture(exitButtonHover);
    UnloadTexture(backButton);
    UnloadTexture(backButtonHover);
    UnloadTexture(returnButton);
    UnloadTexture(returnButtonHover);
    UnloadFont(font); 
    UnloadTexture(background);
}