//Parte de implementação do texto de historia do menu

#include "raylib.h"
#include <unistd.h>
#include "../menu/menu.h"

int continuaScreen (Texture2D background, Font font, Texture2D parte2){

    const char message[920] ={"O nosso heroi ganhou a batalha, mas infelizmente ainda nao ganhou a guerra contra a URSAL.\n\n Ele despertou do monte e conseguiu se fortalecer e recuperar seus poderes para ir atras do seu novo desafio e enfim ser capaz de enfrentar\no maluco do golden shower.\n\nMas como o poder do nosso intrepido heroi vem de todos os queridos cidadaos brasileiros, ele ira precisar novamente de sua ajuda.\nEai, vamos embarcar nessa nova aventura com o estimado salvador da patria, Cabo Daciolo ?\n\nNo proximo Outono..." } ;

    
    Vector2 introTextPosition = {.x = (50), .y = (700)};

    Vector2 fontPosition ={introTextPosition.x,introTextPosition.y};

    Vector2 mousePos = {0.0f, 0.0f};
    int choice = -1;

    ClearBackground(RAYWHITE);
    mousePos = GetMousePosition();

    DrawTexture(background, 0.0, 0.0, WHITE);
    ClearBackground(RAYWHITE);

     if (fontPosition.y >= -40 * 5){
        DrawTextEx(font, message ,fontPosition, 30, 0, WHITE); 
        fontPosition.y -= 0.5;
    }
    DrawTexture(parte2,fontPosition.x+90, fontPosition.y+400, WHITE);

    if (IsKeyPressed(KEY_ENTER)) choice = 1;
    
    if (IsKeyDown(KEY_SPACE)) choice = 0;
   
    return choice;
}
