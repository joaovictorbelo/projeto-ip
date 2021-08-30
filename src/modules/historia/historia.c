//Parte de implementação do texto de historia do menu

#include "raylib.h"
#include <unistd.h>
#include "../menu/menu.h"
int historiaScreen (Texture2D background, Font font, Texture2D returnButton, Texture2D returnButtonHover, 
            int framesCounter){

    const char message[1030] ={"Tudo mudou no Brasil. \n\nNo pais tropical, os tempos nao sao dourados desde 2018, com a eclosao e acentuacao da guerra do Bolsopetismo que levou o incrivel pais a destruicao, os cidadaos\nvivem a margem da politica, com medo de que alguma outra guerra ideologica se acentue e traga novamente o caos ( negativo) a esse pais. Boatos de que os antigos\nfundadores da Ursal se levantaram e pretendem estar em reuniao para elaborar uma estrategia de implementacao da republica socialista da America. As pessoas\nestao comentando que esse reencontro historico, e talvez destruidor, esta marcado para acontecer no dia 01.01.5050 no Forum de Sao Paulo.\n\nSo um heroi ja adormecido no monte, eh capaz de salvar o Brasil da iminente destruicao, ele que ja lutou em outras guerras contra essa implementacao ideologica,\nque ja destruiu satelites mexicanos, Ciros Gomes e ideologias. \n\nCapitao Daciolo eh a solucao de todos os problemas. Nosso heroi precisa recuperar seus poderes, ajude-o em sua jornada!!" } ;

 

    /////////////////////////////Fonte/////////////////////////////
    Vector2 fontPosition = {50,120 };
    Vector2 fontPositionEnter = {50,660};
    Vector2 fontPositionSpace = {50,680};
    ////////////////////////////////////////////////////////////////

    /////////////////////////////Botão Voltar/////////////////////////////

    Rectangle returnButtonBounds = { 50, 50, returnButton.width, returnButton.height };
    
    Vector2 mousePos = {0.0f, 0.0f};
    
    ////////////////////////////////////////////////////////////////
    // while (!WindowShouldClose() && asd == 0){

    if (IsKeyDown(KEY_SPACE)) framesCounter += 8;
    else framesCounter++;

    if (IsKeyPressed(KEY_ENTER)) framesCounter = 0;

    ClearBackground(RAYWHITE);
    mousePos = GetMousePosition();
 
        // BeginDrawing();
    
    DrawTexture(background, 0.0, 0.0, WHITE);
    ClearBackground(RAYWHITE);

    DrawTexture(returnButton, 50, 50, WHITE);

    DrawTextEx(font, TextSubtext(message, 0, framesCounter/10),fontPosition, 25, 0, WHITE); 
    DrawTextEx(font, "Pressione [ENTER] para reiniciar o texto!",fontPositionEnter, 18, 0, LIGHTGRAY); 
    DrawTextEx(font, "Pressione [SPACE] para aumentar a velocidade do texto!",fontPositionSpace, 18, 0, LIGHTGRAY); 

    if (CheckCollisionPointRec(mousePos, returnButtonBounds)) {
        DrawTexture(returnButtonHover, 50, 50, WHITE);
        if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            framesCounter = -1;
            // (*screen) = MENU;
        }  
    }

    return framesCounter;
}
