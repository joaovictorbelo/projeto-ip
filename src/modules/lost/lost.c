//Tela de morte, retornando a opcao de jogar de novo ou nao

#include "raylib.h"

Image loadImageOfLostScreen(int screenWidth, int screenHeight) {
    Image image = LoadImage("./src/asserts/lost/lost_screen.png");
    ImageResize(&image, screenWidth, screenHeight);
    return image;
}

int DrawLostScreen(Texture2D background, Font font) {
    Vector2 postionOfRestart = {50,660};
    Vector2 positionOfBackMenu = {50,680};
    int optionOfChoose = -1;
   
    if (IsKeyPressed(KEY_R)) optionOfChoose = 1;
    
    if (IsKeyDown(KEY_M)) optionOfChoose = 0;
   


    DrawTexture(background, 0.0, 0.0, WHITE);
    DrawTextEx(font, "Pressione [R] para reiniciar o jogo!",postionOfRestart, 18, 0, YELLOW); 
    DrawTextEx(font, "Pressione [M] para voltar ao menu!",positionOfBackMenu, 18, 0, YELLOW); 
    
    return optionOfChoose;
};
