//Tela de "tutorial", mostrando os comandos do jogo e o efeito de cada item/obstaculo

#include "raylib.h"
#include <unistd.h>
#include "../menu/menu.h"
int comoJogarScreen (Texture2D background, Font font, Texture2D returnButton, Texture2D returnButtonHover,Texture2D* texturesObstacules,
Texture2D esquerdo,Texture2D cima,Texture2D direito,Texture2D biblia,Texture2D versiculo, Texture2D space){

    int voltarMenu = 0;
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
    DrawTexture(space, 290, 175, WHITE);
    DrawTextEx(font, "O jogo possui os comandos de andar para FRENTE, para TRAS, PULAR e SPRINT. ",fontPositionLegenda1, 23, 0, WHITE); 

    DrawTextEx(font, "Evite os seguintes obstaculos:  ",fontPosition2, 25, 0, WHITE); 
    DrawTexture(texturesObstacules[0], 50, 350, WHITE);
    DrawTexture(texturesObstacules[1], 150, 350, WHITE);
    DrawTexture(texturesObstacules[2], 220, 350, WHITE);
    DrawTexture(texturesObstacules[3], 310, 350, WHITE);
    DrawTextEx(font, "Evite os seguintes obstaculos para nao perder: \nCABO DACIOLO COMUNISTA,\nCIRO GOMES, SATELITE MEXICANO e SATELITE COMUNISTA. ",fontPositionLegenda2, 23, 0, WHITE); 

    DrawTextEx(font, "Esses itens devem ser coletados:  ",fontPosition3, 25, 0, WHITE); 
    DrawTexture(biblia, 40, 550, WHITE);
    DrawTexture(versiculo, 110, 550, WHITE);
    DrawTextEx(font, "O jogo possui como itens que fornecem bonus:\n A BIBLIA (Imortalidade durante x tempo)\n UM VERSICULO ( Vale 10 pontos)\nO jogo acaba quando 200 pontos forem coletados.  ",fontPositionLegenda3, 23, 0, WHITE); 


    if (CheckCollisionPointRec(mousePos, returnButtonBounds)) {
        DrawTexture(returnButtonHover, 50, 50, WHITE);
        if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            voltarMenu = 1;
            // (*screen) = MENU;
        }  
    }

    return voltarMenu;
}
