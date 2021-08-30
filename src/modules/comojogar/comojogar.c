//Parte de implementação do texto de historia do menu

#include "raylib.h"
#include <unistd.h>
#include "../menu/menu.h"
int comoJogarScreen (Texture2D background, Font font, Texture2D returnButton, Texture2D returnButtonHover,Texture2D* texturesObstacules,
Texture2D esquerdo,Texture2D cima,Texture2D direito,Texture2D biblia,Texture2D versiculo, 
int framesCounter){


    /////////////////////////////Fonte/////////////////////////////
      Vector2 fontPosition1 = {50,120 };
      Vector2 fontPosition2 = {50,300};
      Vector2 fontPosition3 = {50,500};

      Vector2 fontPositionLegenda1 = {550,170};
      Vector2 fontPositionLegenda2 = {550,350};
      Vector2 fontPositionLegenda3 = {550,550};
    ////////////////////////////////////////////////////////////////

    /////////////////////////////Botão Voltar/////////////////////////////

    Rectangle returnButtonBounds = { 50, 50, returnButton.width, returnButton.height };
    
    Vector2 mousePos = {0.0f, 0.0f};

    ClearBackground(RAYWHITE);
    mousePos = GetMousePosition();
 
    
    DrawTexture(background, 0.0, 0.0, WHITE);
    ClearBackground(RAYWHITE);

    DrawTexture(returnButton, 50, 50, WHITE);

    DrawTextEx(font, "Para se movimentar utilize as seguintes teclas: ",fontPosition1, 25, 0, WHITE); 
    DrawTexture(esquerdo, 50, 170, WHITE);
    DrawTexture(cima, 130, 175, WHITE);
    DrawTexture(direito, 210, 170, WHITE);
    DrawTextEx(font, "O jogo possui os movimentos de andar para FRENTE, para TRAS e PULAR. ",fontPositionLegenda1, 20, 0, WHITE); 

    DrawTextEx(font, "Evite os seguintes obstaculos:  ",fontPosition2, 25, 0, WHITE); 
    DrawTexture(obstacules[0], 50, 350, WHITE);
    DrawTexture(obstacules[1], 150, 350, WHITE);
    DrawTexture(obstacules[2], 220, 350, WHITE);
    DrawTexture(obstacules[3], 310, 350, WHITE);
    DrawTextEx(font, "O jogo possui como obstaculos que fazem o jogador PERDER, os seguintes itens : CABO DACIOLO COMUNISTA,\nCIRO GOMES, SATELITE MEXICANO, SATELITE COMUNISTA e SATELITE. ",fontPositionLegenda2, 20, 0, WHITE); 

    DrawTextEx(font, "Esses itens dao bonus:  ",fontPosition3, 25, 0, WHITE); 
    DrawTexture(biblia, 40, 550, WHITE);
    DrawTexture(versiculo, 110, 550, WHITE);
    DrawTextEx(font, "O jogo possui como itens que dão bonus: A BIBLIA (Vale 50 pontos e imortalidade durante x tempo)\n UM VERSICULO ( Vale 10 pontos)  ",fontPositionLegenda3, 20, 0, WHITE); 


    if (CheckCollisionPointRec(mousePos, returnButtonBounds)) {
        DrawTexture(returnButtonHover, 50, 50, WHITE);
        if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            framesCounter = -1;
            // (*screen) = MENU;
        }  
    }

    return framesCounter;
}
