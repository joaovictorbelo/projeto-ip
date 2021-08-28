//Parte de implementação do texto de historia do menu

#include "raylib.h"

int main(void){

    const int screenWidth = 1280;
    const int screenHeight = 720;

    InitWindow(screenWidth, screenHeight, "História| Destroievski");

    const char message[920] ={"Tudo mudou no Brasil. \n\nNo pais tropical, os tempos nao sao dourados desde 2018, com a eclosao e acentuacao da guerra do Bolsopetismo que levou o incrivel pais a destruicao, os cidadaos\nvivem a margem da politica, com medo de que alguma outra guerra ideologica se acentue e traga novamente o caos ( negativo) a esse pais. Boatos de que os antigos\nfundadores da Ursal se levantaram e pretendem estar em reuniao para elaborar uma estrategia de implementacao da republica socialista da America. As pessoas\nestao comentando que esse reencontro historico, e talvez destruidor, esta marcado para acontecer no dia 01.01.5050 no Forum de Sao Paulo.\n\nSo um heroi ja adormecido no monte, eh capaz de salvar o Brasil da iminente destruicao, ele que ja lutou em outras guerras contra essa implementacao ideologica,\nque ja destruiu satelites mexicanos, Ciros Gomes e ideologias. \n\nCapitao Daciolo eh a solucao de todos os problemas." } ;

    int framesCounter = 0;

    SetTargetFPS(120); 

    Image backgroundImage = LoadImage("./src/asserts/menu/fundo.png");
    ImageResize(&backgroundImage, screenWidth, screenHeight);
    Texture2D background = LoadTextureFromImage(backgroundImage);
    UnloadImage(backgroundImage);

    /////////////////////////////Fonte/////////////////////////////
      Font font = LoadFont("./src/font/BarlowCondensed-SemiBold.ttf"); 
      Vector2 fontPosition = {50,120 };
      Vector2 fontPositionEnter = {50,660};
      Vector2 fontPositionSpace = {50,680};
    ////////////////////////////////////////////////////////////////

    /////////////////////////////Botão Voltar/////////////////////////////
    Image returnButtonImage = LoadImage("./src/asserts/menu/return.png");
    ImageResize(&returnButtonImage, returnButtonImage.width/7.7, returnButtonImage.height/7.9);
    Texture2D returnButton = LoadTextureFromImage(returnButtonImage);
    UnloadImage(returnButtonImage);

    Image returnButtonImageHover = LoadImage("./src/asserts/menu/return-hover.png");
    ImageResize(&returnButtonImageHover, returnButtonImageHover.width/7.7, returnButtonImageHover.height/7.9);
    Texture2D returnButtonHover = LoadTextureFromImage(returnButtonImageHover);
    UnloadImage(returnButtonImageHover);
    Rectangle returnButtonBounds = { 50, 50, returnButtonImage.width, returnButtonImage.height };
    
    Vector2 mousePos = {0.0f, 0.0f};
    
    ////////////////////////////////////////////////////////////////
    while (!WindowShouldClose()){

        if (IsKeyDown(KEY_SPACE)) framesCounter += 8;
        else framesCounter++;

        if (IsKeyPressed(KEY_ENTER)) framesCounter = 0;

        ClearBackground(RAYWHITE);
        mousePos = GetMousePosition();
 
        BeginDrawing();
    
            DrawTexture(background, 0.0, 0.0, WHITE);
            ClearBackground(RAYWHITE);

            DrawTexture(returnButton, 50, 50, WHITE);

            DrawTextEx(font, TextSubtext(message, 0, framesCounter/10),fontPosition, 25, 0, WHITE); 
            DrawTextEx(font, "Pressione [ENTER] para reiniciar o texto!",fontPositionEnter, 18, 0, LIGHTGRAY); 
            DrawTextEx(font, "Pressione [SPACE] para aumentar a velocidade do texto!",fontPositionSpace, 18, 0, LIGHTGRAY); 

           if (CheckCollisionPointRec(mousePos, returnButtonBounds)) {
                DrawTexture(returnButtonHover, 50, 50, WHITE);
            }

        EndDrawing();
    }
    
    UnloadTexture(returnButton);
    UnloadTexture(returnButtonHover);
    UnloadFont(font); 
    UnloadTexture(background);
    CloseWindow();        

    return 0;
}